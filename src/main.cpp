#include "knn.h"

int main() {
    srand(time(nullptr));

    // Fill the container with the coordinates
    std::vector<coordinate<int>> points;
    for(int i=0;i<1000000;++i){
        coordinate<int> point(rand()%100, rand()%100);
        points.push_back(point);
    }

    coordinate<int> zero(0,0);

    auto start = std::chrono::high_resolution_clock::now();
    auto k_neighbors = knn(10, points, zero);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

    std::cout<<"Coordinates: "<< points.size()<<
    "\nK Nearest Neighbors: " << k_neighbors.size()<< '\n';

    std::cout<<"------- KNN: -------\n";

    for(auto&i:k_neighbors)
        std::cout<<i<<'\n';

    std::cout<<"Duration: " << duration.count() << " microseconds\n";

    return 0;
}
