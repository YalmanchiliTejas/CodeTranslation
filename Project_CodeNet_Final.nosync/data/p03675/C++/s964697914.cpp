#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <list>
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
using namespace std;
typedef pair<int,int> P;

int main(void){
    int n;
    cin>>n;
    list<int>l;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        if(i%2){
            l.push_back(tmp);
        }else{
            l.push_front(tmp);
        }
    }
    if(n%2)l.reverse();
    list<int>::iterator it;
    bool first=true;
    for(it=l.begin();it!=l.end();it++){
        if(first==false)printf(" ");
        cout<<*it;
        first=false;
    }
    cout<<endl;

    return 0;
}
