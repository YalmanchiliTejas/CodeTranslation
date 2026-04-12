#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;

int main() {
    string S;
    cin >> S;
    set<char> A;
    for (int i = 0; i < 3; i++){
        A.insert(S.at(i));
    }
    if (A.size() == 2){
      cout << "Yes" << endl;  
    }
    else{
        cout << "No" << endl;
    }
    
}
