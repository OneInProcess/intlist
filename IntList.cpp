// File Name:      IntList.cpp
// Author:         Zhao YuDong
// Student Number: 3015230120
// Email:          zhao746714868@qq.com
// Assignment:     IntList
// Version:        c++
// Description:  use some privete variable to save the Inllist's value
//               and the number.


#include <iostream>
#include "IntList.h"

//构造函数，将对应数值存贮
IntList::IntList(int numVals, int val) {
    if (numVals > 0) {
        numberValues = numVals;
        values = new int[numVals];
        for (int i = 0; i < numVals; ++i) {
            values[i] = val;
        }
    } else {
        numberValues = 0;
        values = NULL;
    }
}

//拷贝对象
IntList::IntList(const IntList &il) {
    numberValues = il.size();
    if (numberValues > 0) {
        values = new int[numberValues];
        for (int i = 0; i < numberValues; ++i) {
            values[i] = il.values[i];
        }
    } else {
        values = NULL;
    }
}

IntList::~IntList() {

}

//=运算符重载
IntList &IntList::operator=(const IntList &il) {
    if (this != &il) {
        numberValues = il.size();
        delete[] values;
        values = NULL;
        if (il.numberValues > 0) {
            values = new int[il.numberValues];

            for (int i = 0; i < il.size(); ++i) {
                values[i] = il.values[i];
            }
        }
    }
    return *this;
}

//返回intlist元素的个数
int IntList::size() const {
    return this->numberValues;
}

//判断新旧大小，然后重新构造对象，拷贝内容
void IntList::resize(int n, int val) {
    if (n > this->size()) {
        int *temp = values;
        values = new int[n];
        for (int i = 0; i < numberValues; i++) {
            values[i] = temp[i];
        }
        for (int i = numberValues; i < n; i++) {
            values[i] = val;
        }
        delete temp;
        numberValues = n;
    } else {
        int *temp = values;
        values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = temp[i];
        }
        delete temp;
        numberValues = n;
    }
}

//容量+1，将值放入末尾
void IntList::push_back(int val) {
    this->resize(numberValues + 1, val);
}

//void IntList::print() {
//    for(int i=0;i<this->numberValues;i++){
//        std::cout<<values[i]<<std::endl;
//    }
//}
void IntList::print() {
    std::cout << this->numberValues << ":";
    for (int i = 0; i < this->size(); ++i) {
        std::cout << this->values[i] << " ";
    }
    std::cout << std::endl;
}

int &IntList::operator[](const int index) {
    if (index >= 0) {
        return this->values[index];
    } else {

    }
}

const int &IntList::operator[](const int index) const {
    if (index >= 0) {
        return this->values[index];
    } else {

    }
}

bool operator==(const IntList &il1, const IntList &il2) {
    if (il1.numberValues != il2.numberValues) {
        return false;
    } else {
        for (int i = 0; i < il1.numberValues; i++) {
            if (il1.values[i] != il2.values[i]) {
                return false;
            }
        }
        return true;
    }
}

bool operator!=(const IntList &il1, const IntList &il2) {
    return !(il1 == il2);
}

IntList operator+(const IntList &il1, const IntList &il2) {
    if (il1.numberValues >= il2.numberValues) {
        IntList temp(il1.numberValues, 0);
        for (int i = 0; i < il2.numberValues; i++) {
            temp.values[i] = il1.values[i] + il2.values[i];
        }
        for (int i = il2.numberValues; i < il1.numberValues; i++) {
            temp.values[i] = il1.values[i];
        }
        return temp;
    } else {
        IntList temp(il2.numberValues, 0);
        for (int i = 0; i < il1.numberValues; i++) {
            temp.values[i] = il1.values[i] + il2.values[i];
        }
        for (int i = il1.numberValues; i < il2.numberValues; i++) {
            temp.values[i] = il2.values[i];
        }
        return temp;
    }
}

IntList operator-(const IntList &il1, const IntList &il2) {
    if (il1.numberValues >= il2.numberValues) {
        IntList temp(il1.numberValues, 0);
        for (int i = 0; i < il2.numberValues; i++) {
            temp.values[i] = il1.values[i] - il2.values[i];
        }
        for (int i = il2.numberValues; i < il1.numberValues; i++) {
            temp.values[i] = il1.values[i];
        }
        return temp;
    } else {
        IntList temp(il2.numberValues, 0);
        for (int i = 0; i < il1.numberValues; i++) {
            temp.values[i] = il1.values[i] - il2.values[i];
        }
        for (int i = il1.numberValues; i < il2.numberValues; i++) {
            temp.values[i] = -il2.values[i];
        }
        return temp;
    }
}

std::ostream &operator<<(std::ostream &ost, const IntList &il) {
    if (il.numberValues == 0) {
        ost << il.numberValues << ":";
    } else {
        ost << il.numberValues << ":";
        for (int i = 0; i < il.numberValues; i++) {
            ost << il.values[i] << " ";
        }
    }
    return ost;
}

std::istream &operator>>(std::istream &ist, IntList &il) {
    int n;
    ist >> n;
    il = IntList(n, 0);
    for (int i = 0; i < n; i++) {
        ist >> il.values[i];
    }
    return ist;
}