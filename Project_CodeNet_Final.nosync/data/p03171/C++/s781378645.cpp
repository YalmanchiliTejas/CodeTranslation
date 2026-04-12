#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>
#include <cstring>
#include <iomanip>
#include<queue>
using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
 
#define INF 1000000000
typedef long long  ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define MOD 1000000007

template<typename T>
int vector_finder(std::vector<T> vec, T number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

template<typename T>
T gcd(T a,T b){
	if(b>0){
		return gcd(b, a % b);
	}else{
		return a;
	}
}

template<typename T>
T lcm(T a,T b){
	T g = gcd(a, b);
	return a /g* b ;
}

void clear( std::queue<pair<int,int> > &q )
{
   std::queue<pair<int,int> > empty;
   std::swap( q, empty );
}
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
template<typename T>
int  GetDigit(T num){
    int digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

template<typename T>
std::vector<T> enum_div(T n)//nの約数を列挙
{
	std::vector<T> ret;
	for(T i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i!=1 && i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}


class DisjointSet{
    public:
        vector<int> rank, p;

        DisjointSet(){
        }

        DisjointSet(int size){
            rank.resize(size, 0);
            p.resize(size, 0);
            for (int i = 0; i < size;i++){
                makeSet(i);
            }
        }
        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }

        bool same(int x,int y){
            return findSet(x) == findSet(y);
        }
        void unite(int x,int y){
            link(findSet(x), findSet(y));
        }
        void link(int x,int y){
            if(rank[x]>rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x]==rank[y]){
                    rank[y]++;
                }
            }
        }
        int findSet(int x){
            if(x!=p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};


int main()
{
    int N;
    cin >> N;
    ll a[N];
    REP(i,0,N){
        cin >> a[i];
    }
    ll dp[N + 1][N + 1];
    REP(i, 0, N + 1)
    REP(j, 0, N + 1) dp[i][j] = 0;

    for(int len = 1; len <= N; len++){
		for(int l = 0; l < N - len + 1; l++){
			int r = l + len;
			if((N - len) % 2 == 0){
				dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
			}else{
				dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
			}
		}
	}
 
	cout << dp[0][N] << endl;
}