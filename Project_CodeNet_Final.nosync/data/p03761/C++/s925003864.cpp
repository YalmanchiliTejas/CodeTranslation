#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(void){
    int N;
    cin >> N;
    string S[N];
    for(int i=0;i<N;i++){
        cin >> S[i];
    }
    int mp[N][26];
    for(int i=0;i<N;i++){
        for(int j=0;j<26;j++){
            mp[i][j] = 0;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<S[i].size();j++){
            int k = S[i][j] - 97;
            mp[i][k]++;
        }
    }
    string ans;
    for(int i=0;i<26;i++){
        int r = 100;
        for(int j=0;j<N;j++){
            r = min(r,mp[j][i]);
        }
        while(r > 0){
            ans.push_back(i + 97);
            r--;
        }
    }
    cout << ans << endl;
}
