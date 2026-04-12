#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a, b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define show(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout <<" "<<kbrni;cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n){
        cin >> vec[i];
    }
    if(n == 1){
        cout << vec[0] << "\n";
        return 0;
    }
    if(n % 2 == 0){
        int hoge = n / 2;
        for(int i=hoge;i>=1;i--){
            cout << vec[2*i-1] << " ";
        }
        for(int i=0;i<hoge-1;i++){
            cout << vec[2*i] << " ";
        }
        cout << vec[2*(hoge-1)] << "\n";
    }else{
        int hoge = n / 2;
        for(int i=hoge;i>=0;i--){
            cout << vec[2*i] << " ";
        }
        for(int i=1;i<hoge;i++){
            cout << vec[2*i-1] << " ";
        }
        cout << vec[2*hoge-1] << "\n";
    }
    return 0;
}
