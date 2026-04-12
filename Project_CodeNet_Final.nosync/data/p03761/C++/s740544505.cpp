#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans[55][55];
    for(int i=0;i<55;i++){
        for(int j=0;j<55;j++){
            ans[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        map<char,int> ma;
        for(int j=0;j<s.size();j++){
            ma[s[j]]++;
        }
        for(auto it=ma.begin();it!=ma.end();it++){
            ans[i][it->first-'a']=it->second;
        }
    }
    for(int i=0;i<='z'-'a';i++){
        int tmp=60;
        for(int j=0;j<n;j++){
            tmp=min(tmp,ans[j][i]);
        }
        char ans=i+'a';
        for(int k=0;k<tmp;k++){
            cout << ans;
        }
    }
    cout << endl;
}