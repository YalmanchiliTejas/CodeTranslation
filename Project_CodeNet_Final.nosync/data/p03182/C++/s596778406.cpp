#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;

template<class ValueMonoid, class OperatorMonoid, class Modifier,
	template<class...> class Container=::std::vector>
class LazySegTree{
public:
	using value_structure = ValueMonoid;
	using value_type = typename value_structure::value_type;
	using operator_structure = OperatorMonoid;
	using operator_type = typename operator_structure::value_type;
	using modifier = Modifier;
	using const_reference = const value_type &;
	using container_value_type = Container<value_type>;
	using container_operator_type = Container<operator_type>;
	using size_type = typename container_value_type::size_type;

private:
	container_value_type tree;
	container_operator_type lazy;
	size_type size_, height;

	static size_type getsize(const size_type x){
		size_type ret = 1;
		while(ret < x)
			ret <<= 1;
		return ret;
	}

	static size_type getheight(const size_type x){
		size_type ret = 0;
		while((static_cast<size_type>(1) << ret) < x){
			ret++;
		}
		return ret;
	}

	inline static value_type calc(const value_type a, const value_type b){
		return value_structure::operation(a, b);
	}

	inline static void apply(operator_type &data, const operator_type a){
		data = operator_structure::operation(data, a);
	}

	inline static value_type reflect(const value_type v, const operator_type o){
		return modifier::operation(v, o);
	}

	void push(const size_type index){
		tree[index] = reflect(tree[index], lazy[index]);
		apply(lazy[index << 1], lazy[index]);
		apply(lazy[index << 1 | 1], lazy[index]);
		lazy[index] = operator_structure::identity();
	}

	void calc_node(const size_type index){
		if(tree.size() <= (index << 1 | 1)) return;
		assert(0 < index);
		tree[index] = calc(reflect(tree[index << 1],  lazy[index << 1]),
				reflect(tree[index << 1 | 1], lazy[index << 1 | 1]));
	}

	void build(size_type index){
		while(index >>= 1){
			calc_node(index);
		}
	}

	void propagate(const size_type index){
		for(size_type shift = height; shift ; --shift){
			push(index >> shift);
		}
	}

	void rebuild(){
		for(size_type i = size_-1;i > 0;--i){
			calc_node(i);
		}
	}
public:
	LazySegTree() : size_(0), height(0), tree(), lazy(){}
	LazySegTree(const size_type size)
			: size_(size), height(getheight(size)),
				tree(size << 1, value_structure::initializer()),
				lazy(size << 1, operator_structure::identity()){
		rebuild();
	}
	template<class InputIterator>
	LazySegTree(InputIterator first, InputIterator last)
			: size_(::std::distance(first, last)){
		height = getheight(size_);
		tree = container_value_type(size_, value_structure::identity());
		lazy = container_operator_type(size_ << 1, operator_structure::identity());
		tree.insert(tree.end(), first, last);
		rebuild();
	}

	size_type size() const { return size_; }
	const_reference operator[](const size_type k){
		assert(k < size_);
		propagate(k+size_);
		tree[k+size_] = reflect(tree[k+size_], lazy[k+size_]);
		lazy[k+size_] = operator_structure::identity();
		return tree[k+size_];
	}

	value_type query(size_type l, size_type r){
		assert(l <= r);
		assert(0 <= l && l < size_);
		assert(0 <= r && r <= size_);
		value_type retl = value_structure::identity(),
							 retr = value_structure::identity();
		l += size_;
		r += size_;
		propagate(l);
		propagate(r-1);
		for(; l < r ; l >>= 1, r >>= 1){
			if(l&1){
				retl = calc(retl, reflect(tree[l], lazy[l]));
				l++;
			}
			if(r&1){
				r--;
				retr = calc(reflect(tree[r], lazy[r]), retr);
			}
		}
		return calc(retl, retr);
	}

	void update(size_type l, size_type r, const operator_type& data){
		assert(l <= r);
		assert(0 <= l && l < size_);
		assert(0 <= r && r <= size_);
		l += size_;
		r += size_;
		propagate(l);
		propagate(r - 1);
		for(size_type l_ = l, r_ = r; l_ < r_ ; l_ >>= 1, r_ >>= 1){
			if(l_ & 1) apply(lazy[l_++], data);
			if(r_ & 1) apply(lazy[--r_], data);
		}
		build(l);
		build(r - 1);
	}

	template<class F>
	void update(size_type index, const F& f){
		assert(0 <= index && index < size());
		index += size_;
		propagate(index);
		tree[index] = f(::std::move(tree[index]));
		lazy[index] = operator_structure::identity();
		build(index);
	}

	/*
	template<class F>
	size_type search(const F& f) const { // [0, result) is True and [0, result-1) is not.
		if(f(value_structure::identity()))
			return 0;
		if(!f(tree[1]))
			return size_+1;
		value_type acc = value_structure::identity();
		size_type i = 1;
		while(i < 
	}
	*/
};

using Row = vector<int64>;
using Mat = vector<Row>;

class v_monoid{  
public:
	using value_type = int64;
	static const value_type identity(){return 0;}
	static const value_type initializer(){return 0;}
	static const value_type operation(const value_type& a, const value_type& b){
		return max(a, b);
	}
};

class o_monoid{
public:
	using value_type = int64;
	static const value_type identity(){return 0;}
	static const value_type operation(const value_type& a, const value_type& b){
		return a+b;
	}
};

class modifier{
public:
	static const v_monoid::value_type operation(const v_monoid::value_type& a, const o_monoid::value_type& b){
		return a + b;
	}
};
vector<PLL> l[212345], r[212345]; // (match, val)

int main(void){
	int32 N, M;
	cin >> N >> M;
	REP(i, M){
		int64 a, b, c;
		cin >> a >> b >> c; b++;
		l[a].push_back(PLL(b, c));
		r[b].push_back(PLL(a, c));
	}
	LazySegTree<v_monoid, o_monoid, modifier> lsg(N+2);
	int64 now = 0;
	FOR(i, 1, N+2){
		REP(j, l[i].size()){
			now += l[i][j].sc;
			lsg.update(i, l[i][j].fs, -l[i][j].sc);
		}
		REP(j, r[i].size()){
			now -= r[i][j].sc;
			lsg.update(r[i][j].fs, i, r[i][j].sc);
		}
		lsg.update(i, [&](int64 x){return lsg.query(0, i);});
	}

	cout << lsg.query(0, N+2) << endl;
}
