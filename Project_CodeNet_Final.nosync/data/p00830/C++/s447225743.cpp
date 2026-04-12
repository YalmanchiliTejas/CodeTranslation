// Slip: root did not have entries["."]

#define DEBUG_ON
#define CONDITION true
using namespace std;/*{{{*/

#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <sys/time.h>
#include <vector>

#define INF (1e9)
static const double PI = acos(-1.0);
static const double EPS = 1e-10;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef complex<double> P;

#define FOR(i, b, e) for (typeof(e) i = (b); i != (e); i < (e)? ++i : --i)
#define REP(i, n) FOR(i, 0, n)

#define IFC(c) if(c) continue;
#define IFB(c) if(c) break;
#define IFR(c, r) if(c) return r;

#define OPOVER(_op, _type) inline bool operator _op (const _type &t) const

#define arrsz(a) ( sizeof(a) / sizeof(a[0]) )

#define F first
#define S second
#define MP(a, b) make_pair(a, b)

#define SZ(a) ((LL)a.size())
#define PB(e) push_back(e)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())

#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EACH(c,it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define EXIST(s,e) ((s).find(e)!=(s).end())

#define BIT(n) (assert(n < 64), (1ULL << (n)))
#define BITOF(n, m) (assert(m < 64), ((ULL)(n) >> (m) & 1))

#define RANGE(a, b, c) ((a) <= (b) && (b) <= (c))

#define PQ priority_queue
#define SC static_cast

#ifdef DEBUG_ON
	#define dprt(fmt, ...) if (CONDITION) fprintf(stderr, fmt, ##__VA_ARGS__)
	#define darr(a) if (CONDITION) copy( (a), (a) + arrsz(a), ostream_iterator<int>(cerr, " ") ); cerr << endl
	#define darr_range(a, f, t) if (CONDITION) copy( (a) + (f), (a) + (t), ostream_iterator<int>(cerr, " ") ); cerr << endl
	#define dvec(v) if (CONDITION) copy( ALL(v), ostream_iterator<int>(cerr, " ") ); cerr << endl
	#define darr2(a, n, m) if (CONDITION) FOR(i, 0, (n)){ darr_range( (a)[i], 0, (m) ); }
	#define dvec2(v) if (CONDITION) FOR(i, 0, SZ(v)){ dvec( (v)[i] ); }
	#define WAIT() if (CONDITION) { string _wait_; cerr << "(hit return to continue)" << endl; getline(cin, _wait_); }
	#define dump(x) if (CONDITION) cerr << " [L" << __LINE__ << "] " << #x << " = " << (x) << endl;
	#define dumpf() if (CONDITION) cerr << __PRETTY_FUNCTION__ << endl;
	#define dumpv(x) if (CONDITION) cerr << " [L:" << __LINE__ << "] " << #x << " = "; REP(q, (x).size()) cerr << (x)[q] << " "; cerr << endl;
	#define where() if (CONDITION) cerr << __FILE__ << ": " << __PRETTY_FUNCTION__ << " [L: " << __LINE__ << "]" << endl;
	#define show_bits(b, s) if(CONDITION) { REP(i, s) { cerr << BITOF(b, s-1-i); if(i%4 == 3) cerr << ' '; } cerr << endl; }
#else
	#define cerr if(0) cerr
	#define dprt(fmt, ...)
	#define darr(a)
	#define darr_range(a, f, t)
	#define dvec(v)
	#define darr2(a, n, m)
	#define dvec2(v)
	#define WAIT()
	#define dump(x)
	#define dumpf()
	#define dumpv(x)
	#define where()
	#define show_bits(b, s)
#endif

/* Inline functions */
inline int onbits_count(ULL b) { int c = 0; while(b != 0) { c += (b & 1); b >>= 1; } return c; }
inline int bits_count(ULL b) { int c = 0; while(b != 0) { ++c; b >>= 1; } return c; }
inline int toInt(string s) { int v; istringstream sin(s);sin>>v;return v; }
template<class T> inline string toString(T x) { ostringstream sout;sout<<x;return sout.str(); }
inline double now(){ struct timeval tv; gettimeofday(&tv, NULL); return (static_cast<double>(tv.tv_sec) + static_cast<double>(tv.tv_usec) * 1e-6); }
inline VS split(string s, char delimiter) { VS v; string t; REP(i, s.length()) { if(s[i] == delimiter) v.PB(t), t = ""; else t += s[i]; } v.PB(t); return v; }

/* Tweaks */
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << ", " << d.second << ")";}

/* Frequent stuffs */
int n_dir = 4;
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0}; /* CSS order */
enum direction {
	UP, RIGHT, DOWN, LEFT
};
// int n_dir = 8;
// int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
// enum direction {
	// UP, UPRIGHT, RIGHT, DOWNRIGHT, DOWN, DOWNLEFT, LEFT, UPLEFT
// }
#define FORDIR(d) REP (d, n_dir)

/*}}}*/

class File {
	string name;
	bool dir_flag;
	map<string, File*> entries;

	public:

	File(string _name) {
		name = _name;
		dir_flag = false;
		entries["."] = this;
	}
	File* add(string _name) {
		if (EXIST(entries, _name)) {
			return entries[_name];
		} else {
			dir_flag = true;
			File* nf = new File(_name);
			nf->entries[".."] = this;
			entries[_name] = nf;
			return nf;
		}
	}
	File* get_entry(string _name) {
		if (!dir_flag) {
			return NULL;
		}
		if (EXIST(entries, _name)) {
			return entries[_name];
		} else {
			return NULL;
		}
	}
	File* get_file(string _name) {
		File* f = get_entry(_name);
		if (f == NULL) {
			return NULL;
		} else if (f->is_directory()) {
			return NULL;
		} else {
			return f;
		}
	}
	bool is_directory() {
		return dir_flag;
	}
	void show_tree(int depth) {
		string indent(depth, ' ');
		dprt("%s%s\n", indent.c_str(), name.c_str());
		EACH(entries, e) {
			string key = e->first;
			File* val = e->second;
			IFC(key == "." || key == "..");
			val->show_tree(depth + 1);
		}
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	int N, M;
	while (cin >> N >> M, N | M) {
		File* root = new File("/");
		REP (_, N) {
			string path; cin >> path;
			VS names = split(path, '/');
			File* cwd = root;
			EACH(names, name) {
				if ( (*name).length() ) {
					cwd = cwd->add(*name);
				}
			}
		}

		REP (i, M) {
			string paths[2]; cin >> paths[0] >> paths[1];
			VS queries[2];
			File* files[2] = { root, root };
			REP (j, 2) {
				queries[j] = split(paths[j], '/');
				EACH (queries[j], name) {
					if ( (*name).length() ) {
						files[j] = files[j]->get_entry(*name);
						if (files[j] == NULL) {
							break;
						}
					}
				}
				if (files[j] != NULL
						&& (files[j]->is_directory() || *(queries[j].rbegin()) == "")) {
					files[j] = files[j]->get_file("index.html");
				}
			}
			if (files[0] == NULL || files[1] == NULL) {
				cout << "not found" << endl;
			} else if (files[0] == files[1]) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
	}
}

// vim: foldmethod=marker