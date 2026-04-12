#include<bits/stdc++.h>
using namespace std;char s[9][9];int h,w,i=0;main(){cin>>h>>w;for(;i<h;i++)cin>>s[i];puts(count(s[0],s[10],'#')==h+w-1?"Possible":"Impossible");}