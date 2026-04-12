#include<bits/stdc++.h>

#define fast                     ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int                      long long 
#define pb                       push_back
#define pii                      pair<int,int>
#define vi                       vector<int>
#define vii                      vector<pii>
#define mi                       map<int,int>
#define mii                      map<pii,int>
#define all(a)                   (a).begin(),(a).end()
#define l                        first
#define r                        second
#define sz(x)                    (int)x.size()
#define endl                     '\n'
#define MOD                      1000000007
#define loop(i,a,b)              for(int (i)=(a);(i)<(b);(i)++)
#define rloop(i,a,b)             for(int (i)=(a);(i)>=(b);(i)--)
#define Unique(A)                (A).resize(distance((A).begin(),unique(all((A)))))
#define MXe(A)                   *max_element(all(A))
#define MNe(A)                   *min_element(all(A))
#define SP(val,precision)        fixed << setprecision((precision)) << (val)
#define setBits(x)               __builtin_popcountll(x)
#define zroBits(x)               __builtin_ctzll(x)
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define mem(name,val)            memset(name,val,sizeof(name))
#define traceA(A,x)              cerr<<#A<<": ";loop(i,0,x)cerr<<A[i]<<' ';cerr<<endl
#define traceV(A)                cerr<<#A<<": ";for(auto i:A)cerr<<i<<' ';cerr<<endl
#define maxheap                  priority_queue<int>
#define minheap                  priority_queue<int,vector<int>,greater<int>>

using namespace std;

const int N = 2e5+77;
int A[N];

int32_t main(){
    int n ; cin >> n;
    if(n>=30) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}