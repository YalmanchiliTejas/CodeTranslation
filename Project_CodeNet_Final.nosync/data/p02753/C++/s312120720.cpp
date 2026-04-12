#include <bits/stdc++.h>
using namespace std;

int main(void) {
    char S[3], tmp;
    int flag = 0, i;

    cin >> S;

    for(i=1, tmp=S[0]; i<3; i++){
        if(tmp!=S[i]){
            flag = 1;
            break;
        }
        tmp = S[i];
    }

    if(flag)    cout << "Yes";
    else        cout << "No";

    return 0;
}