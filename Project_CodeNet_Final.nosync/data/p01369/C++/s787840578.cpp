#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <cstdio>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;(i)>=0;(i)--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define PB_VEC(Itr1,Itr2) (Itr1).insert((Itr1).end(),(Itr2).begin(),(Itr2).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())

typedef long long ll;

string lefth="yuiophjklnm";


int main(){
 
    while(true) {
        string s;
        cin>>s;
        if(s=="#")break;
        
        string hand;
        REP(i,s.size()){
            REP(j,lefth.size()){
                if(s[i]==lefth[j]){
                    hand=hand+'1';
                    goto nextf;
                }
            }
            hand=hand+'0';
        nextf:;
        }
        
        char c=hand[0];
        int ans=0;
        REP(i,hand.size()){
            if(c!=hand[i]){
                ans++;
                c=hand[i];
            }
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}