#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N,ans=1;   
    cin>>N;
    int H[20];
    cin>>H[0] ;
    int maxheight=H[0];       
    for(int i=1; i<N; i++){
       cin>>H[i];
       maxheight=max(maxheight,H[i]);
       if(maxheight<=H[i])ans++;
    } 
    cout<<ans<<endl;
    return 0;
}