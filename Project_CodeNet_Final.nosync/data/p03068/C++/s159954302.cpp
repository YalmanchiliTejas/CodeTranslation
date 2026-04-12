#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,k;
    string s;
    cin>>n;
    cin>>s;
    cin>>k;
    
    char m=s[k-1];
    for (int i=0; i<n; i++){
        if(s[i]!=m) s[i]='*';
    }
    
    cout<<s<<endl;
}