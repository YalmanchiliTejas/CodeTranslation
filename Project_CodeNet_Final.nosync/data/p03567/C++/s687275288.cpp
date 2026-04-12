#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
int main(void){
   char s[6];
   cin>>s;
   for(int i=0;i<strlen(s)-1;i++){
       if(s[i]=='A'&&s[i+1]=='C'){
           cout<<"Yes\n";
           return 0;
       }
       
   }
    cout<<"No\n";
}
