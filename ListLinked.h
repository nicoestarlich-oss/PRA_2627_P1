#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    // Constructor: crea una lista vacía
    ListLinked() : first(nullptr), n(0) {}

    // Destructor: libera la memoria de todos los nodos
    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first;
            first = first->next;
            delete aux;
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        return get(pos);
    }

    // Sobrecarga del operador << para imprimir la lista enlazada
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        out << "[";
        if (list.n > 0) {
            out << "\n";
            Node<T>* aux = list.first;
            while (aux != nullptr) {
                out << "  " << aux->data << "\n";
                aux = aux->next;
            }
        }
        out << "]";
        return out;
    }

    // Insertar elemento en la posición pos
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    // Métodos delegados a insert()
    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    // Eliminar el elemento de la posición pos
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        Node<T>* to_delete;
        if (pos == 0) {
            to_delete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            to_delete = prev->next;
            prev->next = to_delete->next;
        }
        T result = to_delete->data;
        delete to_delete;
        n--;
        return result;
    }

    // Obtener elemento en la posición pos
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    // Buscar la posición de un elemento
    int search(T e) override {
        Node<T>* aux = first;
        int idx = 0;
        while (aux != nullptr) {
            if (aux->data == e) {
                return idx;
            }
            aux = aux->next;
            idx++;
        }
        return -1;
    }

    // Comprobar si está vacía
    bool empty() override {
        return n == 0;
    }

    // Devolver número de elementos
    int size() override {
        return n;
    }
};

#endif
