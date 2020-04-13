//
// Created by notpyxl on 12/04/20.
//

#ifndef CS3102_KNN_FSOCUALAYA_KNN_H
#define CS3102_KNN_FSOCUALAYA_KNN_H

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <set>

template <typename T>
struct coordinate{
    T x, y;

    explicit coordinate(T _x=0, T _y=0):x(_x), y(_y){};
    friend std::ostream& operator<<(std::ostream& out, const coordinate coord){
        out<<'('<<coord.x<<", "<<coord.y<<')';
        return out;
    }
};

template <typename T>
coordinate<T> ref;

template <typename T>
double square_sum(const coordinate<T>& a,const coordinate<T>& b){
    return sqrt(
        pow(a.x - b.x, 2) +
        pow(a.y - b.y, 2)
    );
}

template <typename T>
int compare(const void* a, const void * b){
    return square_sum((coordinate<T>*)a, ref<T>) > square_sum((coordinate<T>*) b, ref<T>);
}

template <typename T>
struct classcomp {
    bool operator() (const coordinate<T>& lhs,const coordinate<T>& rhs) const {
        return square_sum(lhs, ref<T>) < square_sum(rhs, ref<T>);
    }
};

template <typename T>
std::set<coordinate<T>, classcomp<T>> knn(int k, std::vector<coordinate<T>>& points, coordinate<T>& point){

    std::set<coordinate<T>, classcomp<T>> k_neighbors;

    for(auto&i:points)
        k_neighbors.insert(i);

     ref<T> = point;

    // std::qsort(&k_neighbors[0], k_neighbors.size(), sizeof(coordinate<T>), compare<T>);

    // k_neighbors.resize(k);
    auto it = k_neighbors.begin();
    std::advance(it, k);

    k_neighbors.erase(it, k_neighbors.end());

    return k_neighbors;

}

#endif //CS3102_KNN_FSOCUALAYA_KNN_H
