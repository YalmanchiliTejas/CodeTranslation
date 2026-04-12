#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cmath>
#include <math.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int i=0;
    int t=0;
    while(s[i]!='\0'){
        if(t==0 && s[i]=='A'){
            t++;
        }
        if(t==1 && s[i]=='C' && s[i-1]=='A'){
            cout<<"Yes"<<endl;
            return 0;
        }
        i++;
    }
    cout<<"No"<<endl;
    return 0;
}