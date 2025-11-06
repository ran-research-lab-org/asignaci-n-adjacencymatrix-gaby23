#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10);
  G.addEdge(0,9);
  G.addEdge(4, 2);


  G.print();

  for(int i = 0; i < 10; i++){
    cout << "Numero de artistas es: " << G.numEdges() << endl;
  }

   for(int i = 0; i < 10; i++){
    cout << "Indegree de " << i << " es: " << G.inDegree(i) << endl;
  }


 for(int i = 0; i < 10; i++){
    cout << "Nodo " << i << (G.isInfluencer(i) ? " si es influencer." : " no es influencer") << endl;
  }
  
  return 0;
}

