#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    int K;
    cin >> K;

    char c = S[K-1];

    replace_if(begin(S), end(S), [&](const auto& x){return x != c;}, '*');

    cout << S << endl;
}