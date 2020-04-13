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
double square_sum(const void* a, coordinate<T> b){
    auto* p_a = (coordinate<T>*) a;
    return sqrt(
        pow(p_a->x - b.x, 2) +
        pow(p_a->y - b.y, 2)
        );
}

template <typename T>
int compare(const void* a, const void * b){
    return square_sum((coordinate<T>*)a, ref<T>) > square_sum((coordinate<T>*) b, ref<T>);
}

template <typename T>
std::vector<coordinate<T>> knn(int k, std::vector<coordinate<T>>& points, coordinate<T>& point){

    std::vector<coordinate<T>> k_neighbors = points;

    ref<T> = point;

    std::qsort(&k_neighbors[0], k_neighbors.size(), sizeof(coordinate<T>), compare<T>);

    k_neighbors.resize(k);
    return k_neighbors;

}

int main() {
    srand(time(nullptr));

    // Fill the container with the coordinates
    std::vector<coordinate<int>> points;
    for(int i=0;i<100;++i){
        coordinate<int> point(rand()%100, rand()%100);
        points.push_back(point);
    }

    coordinate<int> zero(0,0);

    auto start = std::chrono::high_resolution_clock::now();
    auto k_neighbors = knn(10, points, zero);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

    std::cout<<"------- KNN: -------\n";

    for(auto&i:k_neighbors)
        std::cout<<i<<'\n';

    std::cout<<"Duration: " << duration.count() << " microseconds\n";

    return 0;
}
