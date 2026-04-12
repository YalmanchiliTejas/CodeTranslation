#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(void) {
    string S;
    cin >> S;

    bool flag = false;
    for(int i=0; i<3; i++){
        if(S[0]!=S[i])
          flag = true;
    }

    if(flag)
      cout<<"Yes" <<endl;
    else
      cout<<"No" <<endl;

    return 0;
}
