#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<string>ss(n);
    int mn=100;
    for(int i=0;i<n;i++)
        cin >> ss[i];
    
    string ans="";

    vector<int>cnts(26,100);

    for(int j=0;j<n;j++){
        int l=ss[j].length();
        vector<int>temp(26,0);
        for(int k=0;k<l;k++)
            temp[ss[j][k]-'a']++;
        for(int i=0;i<26;i++)
            cnts[i]=min(cnts[i],temp[i]);
    }
    
    for(int i=0;i<26;i++){
        for(int j=0;j<cnts[i];j++)
            cout << (char)(i+'a');
    }

    return 0;
}