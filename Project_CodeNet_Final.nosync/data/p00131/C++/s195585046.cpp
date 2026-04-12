#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }



const int MAX_ROW = 110;
const int MAX_COL = 110;
struct BitMatrix {
    int n, m;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int n_ = 1, int m_ = 1) {n = n_; m = m_;}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
    inline friend ostream& operator << (ostream& s, BitMatrix M) {
        s << endl; 
        for (int i = 0; i < M.n; ++i) {
            for (int j = 0; j < M.m; ++j) s << M.val[i][j];
            s << endl;
        }
        return s;
    }
};

inline BitMatrix operator * (BitMatrix A, BitMatrix B) {
    BitMatrix R(A.n, B.m);
    BitMatrix tB(B.m, B.n);
    for (int i = 0; i < tB.n; ++i) for (int j = 0; j < tB.m; ++j) tB[i][j] = B[j][i];
    for (int i = 0; i < R.n; ++i) for (int j = 0; j < R.m; ++j) R[i][j] = (A[i] & tB[j]).any();
    return R;
}

inline BitMatrix pow(BitMatrix A, long long n) {
    BitMatrix R(A.n, A.n);
    for (int i = 0; i < A.n; ++i) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}

vector<vector<int> > Gauss_Jordan(BitMatrix A, vector<int> b) {
	int rank = 0;
    for (int i = 0; i < A.n; ++i) { A[i][A.m] = b[i]; }
    
    vector<int> core, rem;
	for (int i = 0; i < A.m; ++i) {
		int pivot = -1;
		for (int j = rank; j < A.n; ++j) {
			if (A[j][i]) {
				pivot = j;
				break;
			}
		}
		if (pivot != -1) {
            core.push_back(i);
			swap(A[pivot], A[rank]);
			for (int j = 0; j < A.n; ++j) if (j != rank && A[j][i]) A[j] ^= A[rank];
			++rank;
		}
        else rem.push_back(i);
	}
    
    vector<vector<int> > res;
    for (int i = rank; i < A.n; ++i) 
        if (A[i][A.m]) return res;     // return -1;
    
    vector<int> sol(A.m, 0);
    for (int i = 0; i < core.size(); ++i) sol[core[i]] = A[i][A.m];
    res.push_back(sol);
    
    for (int i = 0; i < rem.size(); ++i) {
        vector<int> temp(A.m, 0);
        temp[rem[i]] = 1;
        for (int j = 0; j < core.size(); ++j) temp[core[j]] = A[j][rem[i]];
        res.push_back(temp);
    }
    
    return res;     // return A[0].size()-rank;
};


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
    BitMatrix A(100, 100);
    vector<int> b(100, 0);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
	A[i*10+j][i*10+j] = 1;
	for (int k = 0; k < 4; ++k) {
	  int ni = i + dx[k], nj = j + dy[k];
	  if (ni < 0 || ni >= 10 || nj < 0 || nj >= 10) continue;
	  A[i*10+j][ni*10+nj] = 1;
	}
	int l;
	cin >> l;
	b[i*10+j] = l;
      }
    }
    vector<int> res = Gauss_Jordan(A, b)[0];
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
	cout << res[i*10+j];
	if (j != 9) cout << " ";
      }
      cout << endl;
    }
    }
  }
}
