#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

template<typename T>
void inputArray(T* p, int a){
    rep(i, a){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    rep(i, a){
        int input;
        cin >> input;
        p -> push_back(input);
    }
}

template <typename T>
void output(T a, int precision = 0) {
    if(precision > 0){
        cout << setprecision(precision)  << a << "\n";
    }
    else{
        cout << a << "\n";
    }
}

#define Max 5100
#define Bl '#'
#define Wh '.'

char S[Max][Max];
int A, B, C, X, Y;

int main(int argc, const char * argv[]) {
    A = inputValue();
    B = inputValue();
    C = inputValue();
    X = inputValue();
    Y = inputValue();

    int Bless = max(Y-X, 0);
    int Aless = max(X-Y, 0);

    ll ans = A * X + B * Y;
    ans = min(ans, (ll)(2*C*X + B*Bless));
    ans = min(ans, (ll)(2*C*Y+A*Aless));

    output(ans);

    return 0;
}