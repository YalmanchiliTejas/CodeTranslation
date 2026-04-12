#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<bitset>
#include<utility>
#include<sstream>
#include<iomanip>
using namespace std;

#define ll long long
#define MP make_pair

int main(void) {
    int n;

    while(1){
        cin>>n;
        int s[100]={};
        double sum=0.0;
        if(n==0)break;

        for (int i = 0; i < n; i++) {
            cin>>s[i];
        }
        
        sort(s,s+n);
        for (int si = 1; si < n-1; si++) {
            sum+=double(s[si]);
        }
        
        double ave = sum/(double)(n-2);
        cout<<int(ave)<<"\n";

    }
    
    return 0;
}
