// Gabriel A. Sanchez; GabrielSR23; 801-23-8372

#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const {
        int count = 0;
        for(int i = 0; i < numVertices; i++){
            for(int k = 0; k < numVertices; k++){
                if(adjMatrix[i][k] == 1) {
                    count++;
                }
            }
        }
        return count;
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");

        int count = 0;
        for(int i = 0; i < numVertices; i++){
            if(adjMatrix[i][u] == 1){
                count++;
            }
        }

        return count;
    }
    

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {
         if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");

        int degree_U = inDegree(u);
        for(int i = 0; i < numVertices; i++){
            if(inDegree(i) > degree_U){
                return false;
            }
        }

        return true;
    }
};

