#include<bits/stdc++.h>
using namespace std;

int chars[50][27]={0};
int mins[27]={0};

int main(){
    int n;
    scanf("%d",&n);
    vector<string> strs;
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        strs.push_back(s);
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<strs[i].size();++j){
                ++chars[i][strs[i][j]-'a'];
        }
    }

    for(int i=0;i<26;++i){
        int minimum=chars[0][i];
        for(int j=1;j<n;++j){
            if(chars[j][i] < minimum)minimum = chars[j][i];
        }
        mins[i] = minimum;
    }
    for(int i=0;i<26;++i){
        while(mins[i] > 0){
            printf("%c",'a'+i);
            --mins[i];
        }
    }
    printf("\n");

    return 0;
}
