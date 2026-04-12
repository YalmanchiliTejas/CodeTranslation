#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
bool Cmp(char a,char b){
    return a<b;
}
int main(){
    char str[50][55];
    memset(str,0,sizeof(str));
    int n,len[26];
    for(int i=0;i<26;i++)len[i]=500;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str[i];
        sort(str[i],str[i]+strlen(str[i]),Cmp);
    }
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<26;j++){
            int count=0;
            while(k<strlen(str[i])&&str[i][k]==char('a'+j)){
                k++;
                count++;
            }
            if(count<len[j])len[j]=count;
        }
    }
    for(int i=0;i<26;i++){
        if(len[i]==500)continue;
        for(int j=0;j<len[i];j++){
            cout<<(char)('a'+i);
        }
    }
    cout<<endl;
    return 0;
}
