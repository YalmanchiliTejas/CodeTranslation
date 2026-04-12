/*
ID: taoxiaa1
PROG: lamps
LANG: C++
*/
//URAL ID:248353QC
#include<bits/stdc++.h>
using namespace std;
//FILE *in, *out;
//in = fopen("lamps.in", "r");
//out = fopen("lamps.out", "w");
//ofstream fout("lamps.out");
//ifstream fin("lamps.in");
int s[200005],t[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        t[i]=s[i];
    }
    sort(t+1,t+1+n);
    int a=t[n/2];
    for(int i=1;i<=n;i++){
        if(s[i]<=a)cout<<t[n/2+1]<<endl;
        else cout<<a<<endl;
    }
    return 0;
}
