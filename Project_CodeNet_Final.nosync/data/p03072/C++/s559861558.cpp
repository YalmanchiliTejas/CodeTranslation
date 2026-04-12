#include<bits/stdc++.h>
#include<map>

using namespace std;
typedef long long ll;
#define Inf 1 << 20
#define MInf -(1 << 20)


#define REP(n) for(int i = 0;i < (int)(n);i++)
#define rep(i,n) for(int i = 0;i < (int)(n);i++)
#define Rep(i,n,m) for(int i = (int)(n); i < (int)(m);i++)
#define rrep(i,n) for(int i = (int)(n - 1); i > -1;i--)
#define RRep(i,n,m) for(int i = (int)(n - 1); i > (int)(m);i--)
#define trav(a, x) for(auto& a : x)

#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))
#define REVERSE(V) reverse(ALL(V))
#define RSORT(V) SORT(V);REVERSE(V)


#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define yes(n) cout << ((n) ? "yes" : "no") << endl;




int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    int count = 1;
    rep(i,N)
    {
        cin >> H.at(i);
    }
    bool is = true;
    Rep(i,1,N)
    {
        is = true;
        Rep(j,0,i)
        {
            if(H[j] > H[i])
                is = false;
        }
        if(is)
            count++;
    }
    cout << count << endl;
}
