#include <iostream>

#include <array>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#include <string>
#include <sstream>

#include <memory>
#include <cassert>

#include <functional>
#include <chrono>

#define SAFE_DELETE(p)       { delete (p);     (p) = nullptr; }
#define SAFE_DELETE_ARRAY(p) { delete[] (p);   (p) = nullptr; }

using namespace std;

namespace ValLib {

	const int MOD = 1000000007;

	typedef unsigned long long ull;

	template <typename Key, typename Value>
	class unordered_vmap;
	template <typename T>
	using sptr = typename std::shared_ptr<T>;
	class vnode;
	class vegde;
	class vgraph;

	template<typename T>
	void fill(vector<vector<T>>& vec, const T& value) {
		for (vector<T>& t : vec) {
			fill(t, value);
		}
	}

	template<typename T>
	void fill(vector<T>& vec, const T& value) {
		fill(vec.begin(), vec.end(), value);
	}

	template<typename T>
	void resize(vector<vector<T>>& vec, int size1, int size2) {
		vec.resize(size1);
		for (vector<T>& t : vec) {
			t.resize(size2);
		}
	}

	template<typename Key, typename Value>
	class umap : public std::unordered_map<Key, Value> {
	public:
		bool containsKey(const Key& key) const;
		bool containsValue(const Value& val) const;
	};

	template<typename Key, typename Value>
	bool umap<Key, Value>::containsKey(const Key& key) const {
		return (this->find(key) != this->end());
	}

	template<typename Key, typename Value>
	bool umap<Key, Value>::containsValue(const Value& val) const {
		for(auto itr = this->begin(); itr != this->end(); ++itr) {
			if (itr->second == val) {
				return true;
			}
		}
		return false;
	}

	class Point {
	public:

		inline Point() :
			x(-1),
			y(-1)
		{}

		inline Point(int _x, int _y) :
			x(_x),
			y(_y)
		{}

		//static Point getDistance(const Point& p1, const Point& p2);

		void setPos(const Point& pos) { x = pos.x; y = pos.y; }
		void setPos(int x, int y) { this->x = x; this->y = y; }

		Point operator+ (const Point &p) const { return move(Point(x + p.x, y + p.y)); }
		Point operator- (const Point &p) const { return move(Point(x - p.x, y - p.y)); }
		void operator+= (const Point &p) { x += p.x; y += p.y; }
		void operator-= (const Point &p) { x -= p.x; y -= p.y; }
		bool operator== (const Point &p) const { return x == p.x && y == p.y; }
		bool operator!= (const Point &p) const { return x != p.x || y != p.y; }
		//bool operator<(const Point &p) const {return x * x + y * y < p.x * p.x + p.y * p.y;}
		const Point& getPos() const { return *this; }

		string to_string() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }

		int x;
		int y;
	};
	//Point Point::getDistance(const Point& p1, const Point& p2) {
	//	return move(Point(abs(p1.x - p2.x), abs(p1.y - p2.y))); 
	//}

	/// <summary>
	/// 素集合データ構造
	/// </summary>
	class UnionFind {
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="N">要素数</param>
		UnionFind(int N) {
			parent.resize(N);
			for (int i = 0; i < N; ++i) {
				parent[i] = i;
			}
		}

		/// <summary>
		/// 要素xの根を探索
		/// </summary>
		/// <param name="x">探索する要素番号(0～N-1)</param>
		/// <returns>要素xの根(0～N-1)</returns>
		int find(int x) {
			if (parent[x] == x) {
				return x;
			} else {
				parent[x] = find(parent[x]); // 経路圧縮(間接的な要素をrootに直接つなぐ)
				return parent[x];
			}
		}

		/// <summary>
		/// ２つの要素の根が同じか
		/// </summary>
		/// <param name="x1">探索する要素番号１(0～N-1)</param>
		/// <param name="x2">探索する要素番号２(0～N-1)</param>
		/// <returns>true: 同じ根, false: 異なる根</returns>
		bool same(int x1, int x2) {
			return find(x1) == find(x2);
		}

		/// <summary>
		/// ２つの要素の根同士を繋ぐ
		/// </summary>
		/// <param name="x1">要素番号１(0～N-1)</param>
		/// <param name="x2">要素番号１(0～N-1)</param>
		void union_elements(int x1, int x2) {
			int rootX1 = find(x1);
			int rootX2 = find(x2);
			parent[rootX2] = rootX1;
		}

	private:
		vector<int> parent;

	};

	class vmath {
	public:

		// 約数を全て求める O(√n)
		static ull calcDivisors(list<ull>* divisors, ull n) {
			divisors->clear();
			if (n <= 0ull) {
				return 0ull;
			}
			divisors->push_back(1ull);
			if (n != 1ull) {
				divisors->push_back(n);
			}
			for (ull i = 2ull; i * i <= n; ++i) {
				if (n % i == 0ull) {
					divisors->push_back(i);
					if (i != n / i) {
						divisors->push_back(n / i);
					}
				}
			}
			return divisors->size();
		}

		// 約数の個数を返す O(√n)
		static ull calcDivisorNum(ull n) {
			if (n <= 0ull) {
				return 0ull;
			}
			ull count = 1ull; // for 1
			if (n != 1ull) {
				++count; // for n
			}
			// for 2～n-1
			for (ull i = 2ull; i * i <= n; ++i) {
				if (n % i == 0ull) {
					count += 1ull;
					if (i != n / i) {
						count += 1ull;
					}
				}
			}
			return count;
		}

		// 素因数分解 O(√n)
		static int calcDecompositPrime(list<ull>* primes, ull n) {
			primes->clear();
			if (n == 0) {
				return 0ull;
			}
			if (n == 1) {
				primes->push_back(1);
				return 1ull;
			}
			// 割る数の初期値
			ull a = 2ull;
			// √n ≧ a ( n ≧ a * a ) の間ループ処理
			while (n >= a * a) {
				if (n % a == 0ull) {
					// a で割り切れたら、a は素因数
					primes->push_back(a);
					// そして、割られる数を a で割る
					n /= a;
				} else {
					// a で割り切れなかったら、 a を 1 増加させる
					a++;
				}
			}
			primes->push_back(n);
			return primes->size();
		}

		// 素因数の数を返す O(√n)
		static ull calcDecompositPrimeNum(ull n) {
			if (n <= 1) {
				return n;
			}
			ull count = 0ull;
			// 割る数の初期値
			ull a = 2ull;
			// √n ≧ a ( n ≧ a * a ) の間ループ処理
			while (n >= a * a) {
				if (n % a == 0ull) {
					// a で割り切れたら、a は素因数
					++count;
					// そして、割られる数を a で割る
					n /= a;
				} else {
					// a で割り切れなかったら、 a を 1 増加させる
					a++;
				}
			}
			++count; // for n
			return count;
		}

		// 階乗
		static ull fact(ull x) {
			if (x == 0ull) {
				return 1ull;
			} else {
				return x * fact(x - 1ull);
			}
		}

		// 順列 nPr
		static ull permutation(int n, int r) {
			assert(n >= r);
			//return fact(n) / fact(n - r);
			ull result = 1;
			for (ull i = n; i > n - r; --i) {
				result *= i;
			}
			return result;
		}

		// 組み合わせ nCr
		// 先にmakePascalTriangleでパスカルの三角形を作成しておく必要がある
		static ull combination(int n, int r) {
			assert(n >= r);
			assert(n <= mPascalTriangleDepth);
			return mPascalTriangle[n][r];
		}

		// 重複組合せ nHr = n+r-1Cr
		// 使いどころ：n人にr個を配るとき、同じ人に何個配っても良い場合とか
		// 4人に5個の◯を配るときa=2,b=0,c=2,d=1のとき、◯◯||◯◯|◯みたいになる。
		// これは◯と|を混ぜた組み合わせで、◯の数がn,棒の数はr-1だから全体でn+r-1
		// (n-r)で割ったものが順列n+r-1Prで、それを更にrで割っているからnHr = n+r-1Cr
		static ull repeatedCombination(int n, int r) {
			return combination(n + r - 1, r);
		}

		// パスカルの三角形。組み合わせの計算に使用するのでこれを先に作成しておく必要がある。
		static void makePascalTriangle(int depth) {
			resize(mPascalTriangle, depth + 1, depth + 1);
			for (int i = 0; i <= depth; ++i) {
				mPascalTriangle[i][0] = 1;
				for (int j = 1; j <= i; ++j) {
					mPascalTriangle[i][j] = mPascalTriangle[i - 1][j] + mPascalTriangle[i - 1][j - 1];
				}
			}
			mPascalTriangleDepth = depth;
		}

		// xのN桁目の数値を得る
		static ull getNDigitNumber(ull x, ull n) {
			return (x / pow(10ull, n - 1ull)) % 10;
		}

		// xのN桁目の数値を得る
		static int getNDigitNumber(int x, int n) {
			assert(n <= 10);
			return (x / pow(10, n - 1)) % 10;
		}

		// xのN乗を求める(バイナリ法) O(logN)
		static ull pow(ull x, ull n) {
			assert(x >= 0ull);
			assert(n >= 0ull);
			if (x == 0ull) {
				if (n == 0ull) {
					return 1ull;
				} else {
					return 0ull;
				}
			}
			ull result = 1ull;
			ull z = x;
			while (n > 0ull) {
				if (n & 1ull) {
					result *= z;
				}
				z *= z;
				n >>= 1;
			}
			return result;
		}

		// xのN乗を求める(バイナリ法) O(logN)
		static int pow(int x, int n) {
			assert(x >= 0);
			assert(n >= 0);
			if (x == 0) {
				if (n == 0) {
					return 1;
				} else {
					return 0;
				}
			}
			int result = 1;
			int z = x;
			while (n > 0) {
				if (n & 1) {
					result *= z;
				}
				z *= z;
				n >>= 1;
			}
			return result;
		}

	private:
		static int mPascalTriangleDepth;
		static vector<vector<ull>> mPascalTriangle;
	};
	int vmath::mPascalTriangleDepth = 0;
	vector<vector<ull>> vmath::mPascalTriangle;

	class vmath_mod {
	public:

		// 階乗
		static ull fact(ull x) {
			ull result = 1ull;
			for (ull i = 1ull; i <= x; ++i) {
				result *= i;
				result %= MOD;
			}
			return result;
		}

		// 順列 nPr
		static ull permutation(int n, int r) {
			assert(n >= r);
			//return fact(n) / fact(n - r);
			ull result = 1;
			for (ull i = n; i > n - r; --i) {
				result *= i;
				result %= MOD;
			}
			return result;
		}

		// 組み合わせ nCr
		// 先にmakePascalTriangleでパスカルの三角形を作成しておく必要がある
		static ull combination(int n, int r) {
			assert(n >= r);
			assert(n <= mPascalTriangleDepth);
			return mPascalTriangle[n][r];
		}

		// 重複組合せ nHr = n+r-1Cr
		// 使いどころ：n人にr個を配るとき、同じ人に何個配っても良い場合とか
		// 4人に5個の◯を配るときa=2,b=0,c=2,d=1のとき、◯◯||◯◯|◯みたいになる。
		// これは◯と|を混ぜた組み合わせで、◯の数がn,棒の数はr-1だから全体でn+r-1
		// (n-r)で割ったものが順列n+r-1Prで、それを更にrで割っているからnHr = n+r-1Cr
		static ull repeatedCombination(int n, int r) {
			return combination(n + r - 1, r);
		}

		// パスカルの三角形。組み合わせの計算に使用するのでこれを先に作成しておく必要がある。
		static void makePascalTriangle(int depth) {
			resize(mPascalTriangle, depth + 1, depth + 1);
			for (int i = 0; i <= depth; ++i) {
				mPascalTriangle[i][0] = 1;
				for (int j = 1; j <= i; ++j) {
					mPascalTriangle[i][j] = (mPascalTriangle[i - 1][j] + mPascalTriangle[i - 1][j - 1]) % MOD;
				}
			}
			mPascalTriangleDepth = depth;
		}

		// xのN桁目の数値を得る
		static ull getNDigitNumber(ull x, ull n) {
			return (x / pow(10ull, n - 1ull)) % 10;
		}

		// xのN桁目の数値を得る
		static int getNDigitNumber(int x, int n) {
			assert(n <= 10);
			return (x / pow(10, n - 1)) % 10;
		}

		// xのN乗を求める O(n)
		static ull pow(ull x, ull n) {
			if (x == 0ull) {
				if (n == 0ull) {
					return 1ull;
				} else {
					return 0ull;
				}
			}
			ull result = 1ull;
			for (ull i = 0ull; i < n; ++i) {
				result *= x;
				result %= MOD;
			}
			return result;
		}

		// xのN乗を求める O(n)
		static int pow(int x, int n) {
			assert(x >= 0);
			assert(n >= 0);
			if (x == 0) {
				if (n == 0) {
					return 1;
				} else {
					return 0;
				}
			}
			int result = 1;
			for (int i = 0; i < n; ++i) {
				result *= x;
				result %= MOD;
			}
			return result;
		}

	private:
		static int mPascalTriangleDepth;
		static vector<vector<ull>> mPascalTriangle;
	};
	int vmath_mod::mPascalTriangleDepth = 0;
	vector<vector<ull>> vmath_mod::mPascalTriangle;

	class vegde {
	public:
		vegde() : vegde(-1) {

		}

		vegde(int cost) :
			mCost(cost) {

		}

		int getCost() const { return mCost; }

	private:
		int mCost;
	};

	class vnode {
	public:
		vnode() : vnode(-1) {

		}

		vnode(int id) :
			mID(id) {

		}

		void addEgde(const vegde& egde, const vnode* node) {
			mEgdeList.emplace_back(egde, node);
		}
		void removeEgde(int nodeID) {
			auto itrNewEnd = std::remove_if(mEgdeList.begin(), mEgdeList.end(), [=](const pair<vegde, const vnode*>& p)->bool {
				return (p.second->getID() == nodeID);
			});
			mEgdeList.erase(itrNewEnd, mEgdeList.end());
		}

		int getID() const { return mID; }
		const list<pair<vegde, const vnode*>>& getEgde() const { return mEgdeList; }
	private:
		list<pair<vegde, const vnode*>> mEgdeList;
		int mID;
	};

	class AdjacencyMatrix {
	public:

		AdjacencyMatrix() {
		}

		AdjacencyMatrix(int nodeNum) {
			resize(mConnectionMap, nodeNum, nodeNum);
			resize(mCostMap, nodeNum, nodeNum);
			resize(mMinimumDistMap, nodeNum, nodeNum);
			resize(mPrevNodeMap, nodeNum, nodeNum);
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mConnectionMap[nodeID1][nodeID2] = true;
			mConnectionMap[nodeID2][nodeID1] = true;
			mCostMap[nodeID1][nodeID2] = cost;
			mCostMap[nodeID2][nodeID1] = cost;
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mConnectionMap[nodeID1][nodeID2] = false;
			mConnectionMap[nodeID2][nodeID1] = false;
			mCostMap[nodeID1][nodeID2] = 0;
			mCostMap[nodeID2][nodeID1] = 0;
		}

		void warshallFloyd(int nodeNum) {
			for (int k = 0; k < nodeNum; ++k) {
				for (int i = 0; i < nodeNum; ++i) {
					for (int j = 0; j < nodeNum; ++j) {
						if (mConnectionMap[i][j]) {
							mMinimumDistMap[i][j] = mCostMap[i][j];
						} else {
							mMinimumDistMap[i][j] = 99999999;
						}
					}
				}
			}
			for (int k = 0; k < nodeNum; ++k) {
				for (int i = 0; i < nodeNum; ++i) {
					for (int j = 0; j < nodeNum; ++j) {
						mMinimumDistMap[i][j] = min(mMinimumDistMap[i][j], mMinimumDistMap[i][k] + mMinimumDistMap[k][j]);
					}
				}
			}
			//for (int i = 0; i < mNodeNum; ++i) {
			//	for (int j = 0; j < mNodeNum; ++j) {
			//		cerr << mMinimumDistMap[i][j] << ", ";
			//	}
			//	cerr << endl;
			//}
		}

		const vector<vector<bool>>& getConnectionMap() const { return mConnectionMap; }
		const vector<vector<int>>& getCostMap() const { return mCostMap; }

		const vector<vector<int>>& getMinimumDistMap() const { return mMinimumDistMap; }
		const vector<vector<int>>& getPrevNodeMap() const { return mPrevNodeMap; }
	private:
		vector<vector<bool>> mConnectionMap;
		vector<vector<int>> mCostMap;

		vector<vector<int>> mMinimumDistMap;
		vector<vector<int>> mPrevNodeMap;

	};

	// グラフ
	class vgraph {
	public:

		const int INF = 1000000;

		vector<bool> check;

		int calc(int N) {
			check.resize(N);
			fill(check, false);
			return calcSub(&mNodes[0]);
		}

		int calcSub(const vnode* node) {
			check[node->getID()] = true;
			int result = 0;
			for (auto t : node->getEgde()) {
				if (check[t.second->getID()]) {
					continue;
				}
				result += calcSub(t.second);
			}
			if (all_of(mNodes.begin(), mNodes.end(), [&](auto& n){
				return check[n.getID()];
				})) {
				result += 1;
			}
			check[node->getID()] = false;

			return result;
		}

		//int calc(int N) {
		//	vector<bool> check(N);
		//	fill(check, false);

		//	stack<const vnode*> nodes;
		//	nodes.push(&mNodes[0]);
		//	check[0] = true;
		//	int result = 0;
		//	while (!nodes.empty()) {
		//		const vnode* node = nodes.top();
		//		nodes.pop();
		//		check[node->getID()] = true;
		//		for (auto t : node->getEgde()) {
		//			if (check[t.second->getID()]) {
		//				continue;
		//			}
		//			nodes.push(t.second);
		//		}
		//		if (all_of(mNodes.begin(), mNodes.end(), [&check](auto& n){
		//			return check[n.getID()];
		//		})) {
		//			result += 1;
		//		}
		//		check[node->getID()] = false;
		//	}

		//	return result;
		//}

		vgraph(int nodeNum) {
			mNodeNum = nodeNum;
			mNodes.resize(nodeNum);
			for (int i = 0; i < nodeNum; ++i) {
				mNodes[i] = move(vnode(i));
			}
			mMinimumDists.resize(mNodeNum);
			mPrevNodes.resize(mNodeNum);
		}

		void addEgde(int nodeID1, int nodeID2) {
			addEgde(nodeID1, nodeID2, 1);
		}

		virtual void addEgde(int nodeID1, int nodeID2, int cost) = 0;
		virtual void removeEgde(int nodeID1, int nodeID2) = 0;

		// ベルマンフォード法を使ってある頂点から全ての頂点への最短距離を求める
		// startからたどり着ける場所に負のループが存在する場合はfalseを返す
		// ダイクストラ法と違い、負のコストの辺があっても最短距離を計算できる
		// O(V*E)
		bool bellmanFord(int start) {

			vector<int>& dist = mMinimumDists;

			fill(dist, INF);
			dist[start] = 0;

			for (int i = 0; i < mNodeNum; ++i) {
				bool update = false;
				for (vnode node : mNodes) {
					for (const pair<vegde, const vnode*> egde : node.getEgde()) {
						int from = node.getID();
						int to = egde.second->getID();
						if (dist[from] == INF) {
							continue;
						}
						if (dist[from] + egde.first.getCost() < dist[to]) {
							dist[to] = dist[from] + egde.first.getCost();
							update = true;

							if (i == mNodeNum - 1) {
								//return false;
							}
						}
					}
				}
				if (!update) {
					break;
				}
			}
			return true;
		}

		// ダイクストラ法を使ってある頂点から全ての頂点への最短距離を求める
		// 負のコストの辺があると最短距離を計算できない点に注意する
		// O(E*logV)
		void dijkstraSearch(int start) {

			// Minimum distances for each nodes
			vector<int>& dpMinDists = mMinimumDists;
			fill(dpMinDists, INF);

			// Result of the previous visited node
			vector<int>& resultPrev = mPrevNodes;
			fill(resultPrev, -1);

			// Create a priority_queue for search.
			typedef pair<int, int> P; // key: その頂点までの最短距離, value: 頂点の番号
			priority_queue<P, vector<P>, greater<P>> pq_node;

			// Mark the current node as visited and enqueue it
			pq_node.push(P(0, start));

			dpMinDists[start] = 0;

			while (!pq_node.empty()) {
				P p = pq_node.top();
				pq_node.pop();
				int nowDist = p.first;
				int nowNodeID = p.second;

				if (dpMinDists[nowNodeID] < nowDist) {
					continue;
				}

				for (const pair<vegde, const vnode*>& egde : mNodes[nowNodeID].getEgde()) {
					const vnode* nextNode = egde.second;
					int nextNodeID = nextNode->getID();

					int nextNodeDist = nowDist + egde.first.getCost();
					if (nextNodeDist < dpMinDists[nextNodeID]) {
						dpMinDists[nextNodeID] = nextNodeDist;
						resultPrev[nextNodeID] = nowNodeID;

						pq_node.push(P(nextNodeDist, nextNodeID));
					}
				}
			}
		}

		int calcMaxDepth() const {
			pair<int, int> farestNodeData = getFarestNodeID(0);
			pair<int, int> farestNodeData2 = getFarestNodeID(farestNodeData.first);
			return farestNodeData2.second;
		}

		int getNodeNum() const { return mNodeNum; }
		const vector<vnode>& getNodes() const { return mNodes; }

		const vector<int>& getMinimumDists() const { return mMinimumDists; }
		const vector<int>& getPrevNodes() const { return mPrevNodes; }
	protected:

		// 引数で受け取ったノードから最も遠いノードのidと距離を返す
		// グラフにループがあると無限ループになるので注意する(つまり木専用)
		pair<int, int> getFarestNodeID(int start) const {
			queue<pair<int, int>> q; // nodeID, このノードまでの距離
			q.push(make_pair(start, 0));
			pair<int, int> finalNodeData;
			vector<bool> opened(mNodeNum);
			fill(opened, false);
			while (!q.empty()) {
				pair<int, int> nodeData = q.front();
				int nodeID = nodeData.first;
				int dist = nodeData.second;
				if (dist > finalNodeData.second) {
					finalNodeData.second = dist;
					finalNodeData.first = nodeID;
				}
				q.pop();
				for (const pair<vegde, const vnode*> egde : mNodes[nodeID].getEgde()) {
					int id = egde.second->getID();
					if (opened[id]) {
						continue;
					}
					opened[id] = true;
					q.push(make_pair(id, dist + egde.first.getCost()));
				}
			}
			return finalNodeData;
		}

		int mNodeNum;
		bool mUseMaps;
		vector<vnode> mNodes;

		vector<int> mMinimumDists;
		vector<int> mPrevNodes;
	};

	// 無向グラフ UnDirected Val Graph.
	class udvgraph : public vgraph {
	public:
		udvgraph(int nodeNum) :
			vgraph(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mNodes[nodeID1].addEgde(move(vegde(cost)), &mNodes[nodeID2]);
			mNodes[nodeID2].addEgde(move(vegde(cost)), &mNodes[nodeID1]);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mNodes[nodeID1].removeEgde(nodeID2);
			mNodes[nodeID2].removeEgde(nodeID1);
		}
	};

	// 隣接行列付きの無向グラフ。ワーシャルフロイドが使える。 UnDirected Val Graph Matrix
	class udvgraph_m : public udvgraph {
	public:

		udvgraph_m(int nodeNum) :
			udvgraph(nodeNum) {
			mAdjacencyMatrix = AdjacencyMatrix(nodeNum);
		}
		void addEgde(int nodeID1, int nodeID2, int cost) {
			udvgraph::addEgde(nodeID1, nodeID2, cost);
			mAdjacencyMatrix.addEgde(nodeID1, nodeID2, cost);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			udvgraph::removeEgde(nodeID1, nodeID2);
			mAdjacencyMatrix.removeEgde(nodeID1, nodeID2);
		}

		void warshallFloyd() {
			mAdjacencyMatrix.warshallFloyd(mNodeNum);
		}

		const vector<vector<bool>>& getConnectionMap() const { return mAdjacencyMatrix.getConnectionMap(); }
		const vector<vector<int>>& getCostMap() const { return mAdjacencyMatrix.getCostMap(); }

		const vector<vector<int>>& getMinimumDistMap() const { return mAdjacencyMatrix.getMinimumDistMap(); }
		const vector<vector<int>>& getPrevNodeMap() const { return mAdjacencyMatrix.getPrevNodeMap(); }
	private:
		AdjacencyMatrix mAdjacencyMatrix;
	};


	// 有向グラフ Directed Val Graph.
	class dvgraph : public vgraph {
	public:
		dvgraph(int nodeNum) :
			vgraph(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mNodes[nodeID1].addEgde(move(vegde(cost)),&mNodes[nodeID2]);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mNodes[nodeID1].removeEgde(nodeID2);
		}

		// 入力のないノードのリストを返す
		list<int> searchStartNodes() const {
			list<int> startNodes;
			unordered_map<int, int> nodesInputs; // key:ノード番号, value:インプット数
			for (auto node : mNodes) {
				for (auto edge : node.getEgde()) {
					++nodesInputs[edge.second->getID()];
				}
			}
			for (int i = 0; i < mNodeNum; ++i) {
				if (nodesInputs.find(i) == nodesInputs.end()) {
					startNodes.push_back(i);
				}
			}
			return move(startNodes);
		}
	};

	// 隣接行列付きの有向グラフ。ワーシャルフロイドが使える。 Directed Val Graph Matrix
	class dvgraph_m : public dvgraph {
	public:

		dvgraph_m(int nodeNum) :
			dvgraph(nodeNum) {
			mAdjacencyMatrix = AdjacencyMatrix(nodeNum);
		}
		void addEgde(int nodeID1, int nodeID2, int cost) {
			dvgraph::addEgde(nodeID1, nodeID2, cost);
			mAdjacencyMatrix.addEgde(nodeID1, nodeID2, cost);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			dvgraph::removeEgde(nodeID1, nodeID2);
			mAdjacencyMatrix.removeEgde(nodeID1, nodeID2);
		}

		void warshallFloyd() {
			mAdjacencyMatrix.warshallFloyd(mNodeNum);
		}

		const vector<vector<bool>>& getConnectionMap() const { return mAdjacencyMatrix.getConnectionMap(); }
		const vector<vector<int>>& getCostMap() const { return mAdjacencyMatrix.getCostMap(); }

		const vector<vector<int>>& getMinimumDistMap() const { return mAdjacencyMatrix.getMinimumDistMap(); }
		const vector<vector<int>>& getPrevNodeMap() const { return mAdjacencyMatrix.getPrevNodeMap(); }
	private:
		AdjacencyMatrix mAdjacencyMatrix;
	};

	class Timer {
	public:
		Timer(const Timer&) = delete;
		Timer& operator=(const Timer&) = delete;
		Timer(Timer&&) = delete;
		Timer& operator=(Timer&&) = delete;
		static Timer& getInstance() {
			static Timer timer;
			return timer;
		}

		void setSize(int size) { mTimes.resize(size); mStopWatches.resize(size); }
		void startTimer(int index) { mStopWatches[index] = chrono::system_clock::now(); }
		void stopTimer(int index) { mTimes[index] += chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - mStopWatches[index]).count(); }
		void addTime(int index, long long millisec) { mTimes[index] += millisec; }
		void resetTimes() { fill(mTimes, 0LL); }
		void resetTime(int index) { mTimes[index] = 0LL; }
		long long getTime(int index) { return mTimes[index]; }
		void outputTimes() { outputTimes(0, mTimes.size()); }
		void outputTimes(int startIndex, int endIndex) {
			for (int i = startIndex; i <= endIndex; ++i) {
				cerr << "Time[" << i << "]: " << mTimes[i] << endl;
			}
		}
	private:
		Timer() {
			mTimes.resize(100);
			mStopWatches.resize(100);
			resetTimes();
		}
		~Timer() = default;

		vector<long long> mTimes;
		vector<chrono::system_clock::time_point> mStopWatches;
	};

	// 立っているビットの数を返す
	static int bitcount8(unsigned char b8) {
		// 8 bits 限定アルゴリズムを利用している
		//c_assert( 8 == (CHAR_BIT * sizeof( b8 )) );

		b8 = (unsigned char)( ((b8 & 0xAA) >> 1) + (b8 & 0x55) );
		b8 = (unsigned char)( ((b8 & 0xCC) >> 2) + (b8 & 0x33) );
		b8 = (unsigned char)( ((b8 & 0xF0) >> 4) + (b8 & 0x0F) );

		return b8;
	}

	// 立っているビットの数を返す
	static int bitcount16(unsigned short w16) {
		// 16 bits 限定アルゴリズムを利用している
		//c_assert( 16 == (CHAR_BIT * sizeof( w16 )) );

		w16 = (unsigned short)( ((w16 & 0xAAAA) >> 1) + (w16 & 0x5555) );
		w16 = (unsigned short)( ((w16 & 0xCCCC) >> 2) + (w16 & 0x3333) );
		w16 = (unsigned short)( ((w16 & 0xF0F0) >> 4) + (w16 & 0x0F0F) );
		w16 = (unsigned short)( ((w16 & 0xFF00) >> 8) + (w16 & 0x00FF) );

		return w16;
	}

	// 立っているビットの数を返す
	static int bitcount32(unsigned long dw32) {
		// 32 bits 限定アルゴリズムを利用している
		//c_assert( 32 == (CHAR_BIT * sizeof( dw32 )) );

		dw32 = ((dw32 & 0xAAAAAAAA) >>  1) + (dw32 & 0x55555555);
		dw32 = ((dw32 & 0xCCCCCCCC) >>  2) + (dw32 & 0x33333333);
		dw32 = ((dw32 & 0xF0F0F0F0) >>  4) + (dw32 & 0x0F0F0F0F);
		dw32 = ((dw32 & 0xFF00FF00) >>  8) + (dw32 & 0x00FF00FF);
		dw32 = ((dw32 & 0xFFFF0000) >> 16) + (dw32 & 0x0000FFFF);

		return dw32;
	}

	// 条件を満たす最小の要素のindexを返す
	// 存在しない場合は-1を返す
	// 使い方の例: int result = binarySearch<int>(A, 0, N - 1, [=](int x) { return x >= K; });
	template<typename T> int binarySearch(vector<T> vec, int beginIndex, int endIndex, function<bool(T)> confilm) {
		// 解が両端にある場合や解なしの判定のために、両端の１つ外側から始める
		int lb = beginIndex - 1; // lower bound
		int ub = endIndex + 1; // upper bound

		while (ub - lb > 1) {
			int mid = (ub + lb) / 2;
			if (confilm(vec[mid])) {
				ub = mid;
			} else {
				lb = mid;
			}
		}

		if (ub == endIndex + 1) {
			// 解なし
			return -1;
		}

		return ub;
	}

}

using namespace ValLib;

int main()
{
	int N, M;
	cin >> N >> M;

	udvgraph graph(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;

		graph.addEgde(a - 1, b - 1, 1);
	}

	int ret = graph.calc(N);
	cout << ret << endl;

	getchar();
	getchar();
}
