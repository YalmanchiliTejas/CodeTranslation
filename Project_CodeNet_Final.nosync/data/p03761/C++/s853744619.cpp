#include <bits/stdc++.h>
using namespace std;

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}

bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}


string s, answo;
int n;
int wo[50][30], ans[30], mem[30];

int main(){
    for(int i = 0; i < 30; i++){
        ans[i] = 1000;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            mem[s[j] - 'a']++;
        }
        for(int j = 0; j < 30; j++){
            ans[j] = min(ans[j], mem[j]);
            mem[j] = 0;
        }
    }

    for(int i = 0; i < 30; i++){
        for(int j = 0; j < ans[i]; j++) answo += (int)'a'+i;
    }
    cout << answo << endl;
}
