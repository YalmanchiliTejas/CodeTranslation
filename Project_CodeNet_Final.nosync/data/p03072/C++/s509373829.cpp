#include <bits/stdc++.h>

using namespace std;

#define llint long long int
#define REP(i,s,l) for(llint i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

int main() {

    int ryokan;
    int height[20];
    cin >> ryokan;
    int count=1;
    int heightMax=0;

    REP(i,0,ryokan){
        cin >> height[i];
    }

    REP(i,0,ryokan-1){
        if(heightMax < height[i]) heightMax = height[i] ;
        if(height[i+1] >= heightMax) count++; 
    }

    cout << count << endl;
    return 0;
}