#include <bits/stdc++.h>
using namespace std;
long n;
vector<vector<int>> alb(50,vector<int>(26,0));
int f(int ab){
    unsigned int min = -1;
    for(int i = 0; i < n; i++){
        if(alb[i][ab] < min)
            min = alb[i][ab];
    }
    return min;
}
int main(){
    cin>>n;
    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < v[i].size(); j++){
            alb[i][v[i][j]-'a']++;
        }
    }
    for(int i = 0; i < 26; i++){
        int num = f(i);
        string o(num,i+'a');
        cout<<o;
    }
    
}