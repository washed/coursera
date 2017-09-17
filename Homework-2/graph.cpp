#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

#include "graph.h"

using namespace std;

Graph::graph::graph()
{
}

Graph::graph::~graph()
{
}

bool Graph::graph::add_node(const node& node)
{
	if (true == add_unique(this->nodes, node))
	{
		cout << "Added node: " << node.get_name() << " to graph!" << endl;
		return true;
	}
	else
	{
		cout << "Unable to add node: " << node.get_name() << " to graph! Node already exists!" << endl;
		return false;
	}
}


bool Graph::graph::add_edge(edge& edge)
{
	// Try to add the nodes from the edge, will be ignored if already present
	add_node(edge.get_node_a());
	add_node(edge.get_node_b());

	if (true == add_unique(this->edges, edge))
	{
		cout << "Added edge: " << edge.get_node_a().get_name() << "-(" << edge.get_distance() << ")->" << edge.get_node_b().get_name()  << " to graph!" << endl;
		return true;
	}
	else
	{
		cout << "Unable to add edge: " << edge.get_node_a().get_name() << "-(" << edge.get_distance() << ")->" << edge.get_node_b().get_name() << " to graph! Edge already exists!" << endl;
		return false;
	}
}

void Graph::graph::find_path_dijkstra(const Graph::node& start, const Graph::node& terminus)
{
	std::vector<node> visited, unvisited;
	node current_node = start;

	map<node&, double> dijkstra_set;
	double distance;

	for (auto node : nodes)
	{
		unvisited.push_back(node);

		if (node == start)
		{
			distance = 0;
		}
		else
		{
			distance = INFINITY;
		}

		dijkstra_set.emplace(std::pair<Graph::node&, double>(node, distance));
	}

	for (auto edge : edges)
	{
		if (edge.get_node_a() == current_node)
		{
			dijkstra_set.find(edge.get_node_b());
		}
	}
}

std::string Graph::node::get_name() const
{
	return this->name;
}

const Graph::node& Graph::edge::get_node_a() const
{
	return a;
}

const Graph::node& Graph::edge::get_node_b() const
{
	return b;
}

const unsigned int Graph::edge::get_distance() const
{
	return distance;
}

bool Graph::path::add_edge(const Graph::edge& edge)
{
	if (true == add_unique(edges, edge))
	{
		cout << "Added edge: " << edge.get_node_a().get_name() << "-(" << edge.get_distance() << ")->" << edge.get_node_b().get_name() << " to path!" << endl;
		return true;
	}
	else
	{
		cout << "Unable to add edge: " << edge.get_node_a().get_name() << "-(" << edge.get_distance() << ")->" << edge.get_node_b().get_name() << " to path! Edge already exists!" << endl;
		return false;
	}
}

const unsigned int Graph::path::get_distance()
{
	unsigned int distance = 0;
	for (auto edge : edges)
	{
		distance += edge.get_distance();
	}
	return distance;
}