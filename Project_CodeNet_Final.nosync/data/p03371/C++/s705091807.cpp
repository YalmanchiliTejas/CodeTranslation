#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(auto (i)=a;i<b;i++)
#define list(i, N) for(auto (i)=0;i<N;i++)

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll, ll> pi;
#define mp make_pair
#define pb push_back
#define eb emplace_back

#define int ll
#define INF 1e18+5
#define mod 1000000007

template<class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

    //first check if option C is cheaper than options A and B combined
    double halfA = (double)A/2; double halfB = (double)B/2;
    bool isCBetter = (halfA + halfB) >= C;
    //Casework lol
    if(isCBetter){
        int option1 = 2*max(X,Y)*C; //its okay to have more pizzas than needed
        //For option 2, casework on the minimum value
        int option2 = 0;
        if(min(X,Y)==X){
            //get 2*X pizzas of type C
            option2 += 2*X*C;
            Y -= X;
            option2 += B*Y;
        }else {
            option2 += 2*Y*C;
            X -= Y;
            option2 += A*X;
        }
        cout << min(option1,option2) << "\n";
    }else {
        //C is pricey to get
        cout << X*A + Y*B << "\n"; //better to buy individually
    }

    return 0;
}