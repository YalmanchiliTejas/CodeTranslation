#include "bits/stdc++.h"
#define INT long long
using namespace std;

int main()
{
    int a[5],b[5];
    char c[5]={'A','B','C','D','E'};
    for(;;){
        for(int i=0;i<5;i++){
            cin >> a[i] >>b[i];
            if(a[i]==0&&b[i]==0) return 0;
        }
        pair<int,char> p[5];
        for(int i=0;i<5;i++){
            p[i]=make_pair(a[i]+b[i],c[i]);
        }
        sort(p,p+5);
        reverse(p,p+5);
        cout << p[0].second << " " << p[0].first << endl;
    }
    return 0;
}

