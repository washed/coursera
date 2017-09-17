#pragma once

#include <vector>
#include <algorithm>
#include <string>

namespace Graph
{
	class node
	{
	public:
		node() {};
		node(const std::string name) : name(name) {};
		~node() {};

		std::string get_name() const;
	private:
		const std::string name;
	};

	class edge
	{
	public:
		edge(node a, node b, unsigned int distance) : a(a), b(b), distance(distance) {};
		edge(std::string a_name, std::string b_name, unsigned int distance) : a(node(a_name)), b(node(b_name)), distance(distance) {};

		~edge() {};

		const node& get_node_a() const;
		const node& get_node_b() const;
		const unsigned int get_distance() const;

	private:
		const node a;
		const node b;
		const unsigned int distance;
	};

	class path
	{
	public:
		bool add_edge(const edge& edge);
		const unsigned int get_distance();
	private:
		std::vector<edge> edges;
	};

	class graph
	{
	public:
		graph();
		~graph();

		bool add_edge(edge& edge);
		void Graph::graph::find_path_dijkstra(const Graph::node& start, const Graph::node& terminus);
		//Graph::path find_path(const node&  start, const node&  terminus);

	private:
		std::vector<node> nodes;
		std::vector<edge> edges;
		std::vector<path> paths;

		bool add_node(const node& node);
	};

	inline bool operator==(const Graph::node& lhs, const Graph::node& rhs) {
		return (lhs.get_name() == rhs.get_name());
	}

	inline bool operator!=(const Graph::node& lhs, const Graph::node& rhs) {
		return !(lhs == rhs);
	}

	inline bool operator==(const Graph::edge& lhs, const Graph::edge& rhs) {
		return ((lhs.get_node_a() == rhs.get_node_a()) && (lhs.get_distance() == rhs.get_distance()));
	}

	inline bool operator!=(const Graph::edge& lhs, const Graph::edge& rhs) {
		return !(lhs == rhs);
	}

	template<typename T>
	bool add_unique(std::vector<T>& collection, const T& item);

	template<typename T>
	bool contains(std::vector<T>& collection, const T& item);
}

template<typename T>
bool Graph::add_unique(std::vector<T>& collection, const T& item)
{
	if (true != contains(collection, item))
	{
		collection.push_back(item);
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool Graph::contains(std::vector<T>& collection, const T& item)
{
	return (std::find(collection.begin(), collection.end(), item) != collection.end());
}

