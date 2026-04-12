#include<iostream>
#include<map>
#include<string>

using namespace std;

string alpha="abcdefghijklmnopqrstuvwxyz";

int main(){
    int n;
    string s[51];
    map<char, int> m;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<26;i++){
        m[alpha[i]]=10000;
    }
    for(int i=0;i<n;i++){
        map<char, int> tmpm;
        for(int j=0;j<26;j++){
            tmpm[alpha[j]] = 0;
        }
        for(int j=0;j<s[i].length();j++){
            tmpm[s[i][j]]++;
        }
        for(int j=0;j<26;j++){
            m[alpha[j]] = min(m[alpha[j]], tmpm[alpha[j]]);
        }
    }
    for(int i=0;i<26;i++){
        while(m[alpha[i]]>0){
            cout << alpha[i];
            m[alpha[i]]--;
        }
    }
    cout << endl;
}