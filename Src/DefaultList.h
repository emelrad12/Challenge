#pragma once
template<class T>
class DefaultList {
public:

    DefaultList() {

    }

    DefaultList(std::initializer_list<T> l) {

    }

    void Append(DefaultList<T> &second) {

    }

    DefaultList<T> Concatenate(DefaultList<T> &second) {

    }

    DefaultList<T> Filter(bool (*func)(int)) {

    }

    int Length() {
        return 0;
    };

    DefaultList<T> &Map(T (*func)(T)) {

    };

    template<class TAcc>
    TAcc FoldL(TAcc (*func)(T, TAcc), TAcc acc) {

    };

    template<class TAcc>
    TAcc FoldR(TAcc (*func)(T, TAcc), TAcc acc) {

    };

    DefaultList<T> &Reverse() {

    };

    bool Equals(DefaultList<T> &second) {
        return false;
    }

    virtual bool Equals(std::initializer_list<T> second) {
        return false;
    }
};