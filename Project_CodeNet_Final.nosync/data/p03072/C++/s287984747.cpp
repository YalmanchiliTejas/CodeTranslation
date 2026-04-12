#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

vector<ll> A;

bool tallest(ll index){
    ll h = A[index];
    FOR(i, 0, index){
        if(A[i]>h){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;
    A.resize(N);

    FOR(i, 0, N){
        cin >> A.at(i);
    }

    if(N==1){
        p(1);
        return 0;
    }

    ll count = 1;
    FOR(i, 1, N){
        if(tallest(i)){
            count++;
        }
    }

    p(count);
    
    return 0;
}