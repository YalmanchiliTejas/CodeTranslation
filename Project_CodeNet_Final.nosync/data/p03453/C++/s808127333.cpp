#include <limits>
#include <queue>
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cstddef>
#include <type_traits>
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
template <typename T>
struct weight_ {
	using weight_type = T;
	weight_type weight;
	explicit weight_(const weight_type& w = weight_type())
		: weight(w)
	{ }
};
template <typename T>
using weight = weight_<T>;
}
namespace detail {
template <typename T, typename... Params>
struct edge_param_wrapper : public T, edge_param_wrapper<Params...> {
	template <typename U, typename... Args>
	explicit edge_param_wrapper(U&& x, Args&&... args)
		: T(std::forward<U>(x))
		, edge_param_wrapper<Params...>(std::forward<Args>(args)...)
	{ }
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
	size_t size() const {
		return m_edges.size();
	}
	const edge_list& operator[](vertex_t u) const {
		return m_edges[u];
	}
	edge_list& operator[](vertex_t u){
		return m_edges[u];
	}
	template <typename... Args>
	void add_edge(vertex_t from, Args&&... args){
		m_edges[from].emplace_back(std::forward<Args>(args)...);
	}
};
}
namespace loquat {
template <int MOD>
class modulus_integer {
public:
	typedef modulus_integer<MOD> self_type;
private:
	int m_value;
	static self_type unsafe_construct(int x) noexcept {
		self_type y;
		y.m_value = x;
		return y;
	}
public:
	modulus_integer() noexcept
		: m_value(0)
	{ }
	modulus_integer(int x) noexcept
		: m_value(x % MOD)
	{
		if(m_value < 0){ m_value += MOD; }
	}
	int operator*() const noexcept { return m_value; }
	self_type& operator=(const self_type& x) noexcept {
		m_value = x.m_value;
		return *this;
	}
	self_type operator+(const self_type& x) const noexcept {
		const int y = m_value + x.m_value;
		return unsafe_construct(y >= MOD ? y - MOD : y);
	}
	self_type operator-(const self_type& x) const noexcept {
		const int y = m_value - x.m_value;
		return unsafe_construct(y < 0 ? y + MOD : y);
	}
	self_type operator*(const self_type& x) const noexcept {
		return unsafe_construct(
			static_cast<long long>(m_value) * x.m_value % MOD);
	}
	self_type& operator+=(const self_type& x) noexcept {
		return (*this = *this + x);
	}
	self_type& operator-=(const self_type &x) noexcept {
		return (*this = *this - x);
	}
};
template <int MOD>
inline std::ostream& operator<<(
	std::ostream& os, const modulus_integer<MOD>& x)
{
	os << *x;
	return os;
}
}
namespace loquat {
template <typename T>
constexpr inline auto positive_infinity() noexcept
	-> typename std::enable_if<std::is_integral<T>::value, T>::type
{
	return std::numeric_limits<T>::max();
}
}
using namespace std;
using ll = long long;
using edge = loquat::edge<loquat::edge_param::weight<ll>>;
using mint = loquat::modulus_integer<1000000007>;
template <typename EdgeType>
std::pair<std::vector<typename EdgeType::weight_type>, std::vector<mint>>
dijkstra(loquat::vertex_t source, const loquat::adjacency_list<EdgeType>& graph){
	using weight_type = typename EdgeType::weight_type;
	using pair_type = std::pair<weight_type, loquat::vertex_t>;
	using queue_type = std::priority_queue<
		pair_type, std::vector<pair_type>, std::greater<pair_type>>;
	const auto inf = loquat::positive_infinity<weight_type>();
	const auto n = graph.size();
	std::vector<weight_type> dist(n, inf);
	std::vector<mint> ways(n);
	queue_type pq;
	dist[source] = 0;
	ways[source] = 1;
	pq.emplace(0, source);
	while(!pq.empty()){
		const auto x = pq.top().first;
		const auto u = pq.top().second;
		pq.pop();
		if(dist[u] < x){ continue; }
		for(const auto& e : graph[u]){
			const auto v = e.to;
			const auto y = x + e.weight;
			if(y < dist[v]){
				dist[v] = y;
				ways[v] = ways[u];
				pq.emplace(y, v);
			}else if(y == dist[v]){
				ways[v] += ways[u];
			}
		}
	}
	return std::make_pair(dist, ways);
}
int main(){
	ios_base::sync_with_stdio(false);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	--s; --t;
	loquat::adjacency_list<edge> g(n);
	for(int i = 0; i < m; ++i){
		int u, v, d;
		cin >> u >> v >> d;
		--u; --v;
		g.add_edge(u, v, d);
		g.add_edge(v, u, d);
	}
	const auto fwd = dijkstra(s, g);
	const auto bwd = dijkstra(t, g);
	const auto fwd_dist = fwd.first;
	const auto bwd_dist = bwd.first;
	const auto fwd_ways = fwd.second;
	const auto bwd_ways = bwd.second;
	const auto st_dist = fwd_dist[t];
	mint answer = fwd_ways[t] * bwd_ways[s];
	for(int u = 0; u < n; ++u){
		if(fwd_dist[u] + bwd_dist[u] == st_dist){
			if(fwd_dist[u] == bwd_dist[u]){
				const auto c = fwd_ways[u] * bwd_ways[u];
				answer -= c * c;
			}
		}
		for(const auto& e : g[u]){
			const auto v = e.to;
			const auto w = e.weight;
			if(fwd_dist[u] + bwd_dist[v] + w != st_dist){ continue; }
			const auto t = fwd_dist[u] - bwd_dist[v];
			if(-w < t && t < w){
				const auto f = fwd_ways[u] * bwd_ways[v];
				const auto b = bwd_ways[v] * fwd_ways[u];
				answer -= f * b;
			}
		}
	}
	cout << answer << endl;
	return 0;
}
