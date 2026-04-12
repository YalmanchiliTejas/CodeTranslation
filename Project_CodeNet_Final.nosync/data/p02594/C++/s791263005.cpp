#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<long long>> vvll;
typedef long double ld;
typedef std::vector<long double> vld;
typedef std::vector<std::vector<long double>> vvld;
using namespace std;
void yesno(bool state);

void Main(){
    ll N;
    cin >> N;
    yesno(N >= 30);
}

int main(int argc, char const *argv[])
{
    Main();
    return 0;
}

void yesno(bool state){
    if(state)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}