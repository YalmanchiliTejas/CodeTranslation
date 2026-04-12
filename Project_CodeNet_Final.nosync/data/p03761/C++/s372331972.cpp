#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin >> n;
    int in[n][26];
    memset(in,0,sizeof(in));
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            in[i][(int)(s[j]-'a')] ++;
        }   
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            cout <<i << " " << j << " " <<  in[i][j] << endl;
        }
    }*/
    for(int j=0;j<26;j++){
        int ans = 5000;
        for(int i=0;i<n;i++){
            if(ans >in[i][j]){
                ans = in[i][j];
            }
        }
       // cout << j << " " << ans[j] << endl;
        for(int i=0;i<ans;i++){
            cout << (char)(j+'a');
        }
    }
    cout << endl;
    return 0;
}