#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    
    int l = S.size();
    // SのK番目の文字
    char rep = S[K-1];
    
    for(int i=0;i<l;i++){
        if(S[i] != rep)
            cout << '*';
        else
            cout << S[i];
        
    }
    cout << endl;
    
}