#include "graph.h"

#include <iostream>

int main()
{
	using namespace Graph;
	using namespace std;

	graph my_graph;

	std::vector<edge> edges = {
		edge("A", "B", 5),
		edge("C", "D", 10),
		edge("A", "C", 1),
		edge("B", "D", 20)
	};

	for (auto edge : edges)
	{
		my_graph.add_edge(edge);
	}

	my_graph.find_path_dijkstra(node("A"), node("D"));

	std::cout << "Exiting..." << endl;
	return 0;
}