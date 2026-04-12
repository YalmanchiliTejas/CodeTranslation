#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    for (int i = 0;i < 3;i++) {
        if(S[0] == S[1] && S[1] == S[2]){
            cout<<"No"<<endl;
            return 0;
        }else {
            cout<<"Yes"<<endl;
            return 0;
        }

    }
}


