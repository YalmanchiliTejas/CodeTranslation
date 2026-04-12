#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define divceil(A, B) ((A + (B - 1)) / B)
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr

using namespace std;

int main(){

    int x,y,z;
    cin >> x >> y >> z;

    x = x - z;

    cout << x / (y + z) << endl;
    return 0;
}
