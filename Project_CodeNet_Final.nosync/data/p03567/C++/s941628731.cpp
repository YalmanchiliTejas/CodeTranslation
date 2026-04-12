#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#define ll long long
#define MAXN 100000
using namespace std;



int main() {
    string S;
    cin>>S;
    bool ok=false;
    for(int i=0;i<S.size()-1;i++) {
        if (S[i]=='A' && S[i+1]=='C')
            ok=true;
    }
    cout << (ok ? "Yes" : "No") << endl;
}