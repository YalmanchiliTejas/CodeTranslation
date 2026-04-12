#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define res(n) resize(n)
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;



int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X>> Y;
    
    if(X < Y){
        swap(X,Y);swap(A,B);
    }
    
    int ans = A*X+B*Y;
    
    ans = min(ans, C*Y*2 + A*(X-Y));
    
    ans = min(ans, C*2*X);
    
    

    out(ans);


    return 0;
}
