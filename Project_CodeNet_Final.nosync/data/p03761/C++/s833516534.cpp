#include <iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int s_count[n][26] = {};

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(char c: s){
            s_count[i][c-'a'] ++;
        }
    }

    string ans = "";
    for(int i=0;i<26;i++){
        int min_count = 100;
        for(int j=0;j<n;j++){
            min_count = min(min_count,s_count[j][i]);
        }
        if(min_count<100){
            ans += string(min_count, char('a'+i));
        }
    }

    cout<<ans<<endl;
}