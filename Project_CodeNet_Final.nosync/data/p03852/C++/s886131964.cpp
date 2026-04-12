#include <bits/stdc++.h>
using namespace std;
 
struct edge {int /*from,*/to,cost;};
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> PP;
typedef vector<int> VI;
typedef vector<long long int> VL;
typedef vector<edge> VE;
static const int MOD = 1000000007;
//static const int INF = 2147483647;
//static const long long INF = 9223372000000000000;
//static const long long INF = 9223372000000000000/2;
//static const int INF = 1000010000;
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define np next_permutation
#define pq priority_queue
#define SZ(a) int((a).size())
#define LEN(a) int((a).length())
#define MAX(a,b,c) max((a),max((b),(c)))
#define MIN(a,b,c) min((a),min((b),(c)))
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP1(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREP1(i,x) for(int i=((int)(x));i>0;i--)
//#define int ll

signed main(){
    char c;
    scanf("%c",&c);
    if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o') puts("vowel");
    else puts("consonant");
    return 0;
}