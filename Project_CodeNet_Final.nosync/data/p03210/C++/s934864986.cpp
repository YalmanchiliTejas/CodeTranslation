#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
typedef unsigned long ul;
typedef pair<ul, ul> P;
 
int main()
{
    int n;
    cin >> n;
    if(n==7||n==5||n==3){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
 
    return 0;
}