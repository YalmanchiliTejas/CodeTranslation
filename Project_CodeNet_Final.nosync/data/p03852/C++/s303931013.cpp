#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;

typedef long long ll;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    char a;
    while(cin>>a){
        getchar();
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
            cout<<"vowel"<<endl;
        else
            cout<<"consonant"<<endl;
    }
    return 0;
}
