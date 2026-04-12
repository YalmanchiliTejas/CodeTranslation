#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;

int main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    char q=s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]!=q)s[i]='*';
    }
    cout<<s<<endl;
}

   
