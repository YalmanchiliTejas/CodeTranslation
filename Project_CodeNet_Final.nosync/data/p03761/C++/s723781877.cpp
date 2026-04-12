#include<iostream>
#include<string>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s[50];
    for(int i(0);i<n;i++){
        cin>>s[i];
    }
    int cnt[50][26]={0};
    for(int i(0);i<n;i++){
        for(int j(0);j<s[i].size();j++){
            cnt[i][(int)(s[i][j]-97)]++;
        }
    }
    for(int i(0);i<26;i++){
        int min(cnt[0][i]);
        for(int j(1);j<n;j++){
            if(min>cnt[j][i])min = cnt[j][i];
        }
        for(int j(0);j<min;j++){
            cout<<(char)(i+97);
        }
    }
    cout<<endl;
    return 0;
}