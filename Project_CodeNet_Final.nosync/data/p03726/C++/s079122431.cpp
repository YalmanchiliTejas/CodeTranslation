#include <cstddef>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
namespace loquat {
using vertex_t = size_t;
}
namespace loquat {
namespace edge_param {
struct to_ {
	vertex_t to;
	explicit to_(vertex_t t = 0)
		: to(t)
	{ }
};
}
namespace detail {
template <typename T, typename... Params>
struct edge_param_wrapper : public T, edge_param_wrapper<Params...> {
};
template <typename T>
struct edge_param_wrapper<T> : public T {
	template <typename U>
	explicit edge_param_wrapper(U&& x)
		: T(std::forward<U>(x))
	{ }
};
}
template <typename... Params>
struct edge : public detail::edge_param_wrapper<edge_param::to_, Params...> {
	template <typename... Args>
	explicit edge(Args&&... args)
		: detail::edge_param_wrapper<edge_param::to_, Params...>(
			std::forward<Args>(args)...)
	{ }
};
}
namespace loquat {
template <typename EdgeType>
class adjacency_list {
public:
	using edge_type = EdgeType;
	using edge_list = std::vector<edge_type>;
private:
	std::vector<std::vector<EdgeType>> m_edges;
public:
	explicit adjacency_list(size_t n)
		: m_edges(n)
	{ }
	const edge_list& operator[](vertex_t u) const {
		return m_edges[u];
	}
	template <typename... Args>
	void add_edge(vertex_t from, Args&&... args){
		m_edges[from].emplace_back(std::forward<Args>(args)...);
	}
};
}
using namespace std;
using edge = loquat::edge<>;
int solve(int u, int p, const loquat::adjacency_list<edge>& g){
	int sum = 0, children = 0;
	for(const auto& e : g[u]){
		if(e.to == p){ continue; }
		++children;
		const int t = solve(e.to, u, g);
		if(t < 0){ return t; }
		sum += t;
	}
	if(sum >= 2){ return -1; }
	return (sum == 1 ? 0 : 1);
}
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	loquat::adjacency_list<edge> g(n);
	for(int i = 1; i < n; ++i){
		int a, b;
		cin >> a >> b;
		--a; --b;
		g.add_edge(a, b);
		g.add_edge(b, a);
	}
	const int t = (n % 2 == 1 ? -1 : solve(0, -1, g));
	cout << (t < 0 ? "First" : "Second") << endl;
	return 0;
}
