#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>
#include<array>
#include<numeric>
#include<iomanip>

using namespace std;
typedef long long int ll;

int h,w,a[10][10],vs=0;
string s;
bool r=false;

int main(){
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        cin>>s;
        for(int j=0;j<w;j++){
            a[i][j]=s[j]=='#';
            vs+=a[i][j];
        }
    }
    vector<vector<int>> st={{0,0,0}},stm;
    while(st.size()!=0){
        stm={};
        for(vector<int> itr:st){
            if(itr[2]==vs-1)r=true;
            //printf("%d\n",itr[2]);
            if(itr[0]<h){
                if(a[itr[0]+1][itr[1]])stm.push_back({itr[0]+1,itr[1],itr[2]+1});
            }
            if(itr[1]<w){
                if(a[itr[0]][itr[1]+1])stm.push_back({itr[0],itr[1]+1,itr[2]+1});
            }
        }
        if(r)break;
        st=stm;
    }
    printf(r ? "Possible\n":"Impossible\n");
}