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
#include <iomanip>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;(i)>=0;(i)--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define PB_VEC(Itr1,Itr2) (Itr1).insert((Itr1).end(),(Itr2).begin(),(Itr2).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())

typedef long long ll;

int main(){

    while(true){
        int n;
        cin>>n;
        if(n==0)break;
        
        int dice[4]={5,3,2,4};
        int up=1;
        int ans=1;
        
        REP(i,n){
            string dire;
            cin>>dire;
            if(dire=="North"){
                dice[0]=up;
                up=dice[2];
                dice[2]=7-dice[0];
            }else if(dire=="East"){
                dice[1]=up;
                up=dice[3];
                dice[3]=7-dice[1];
            }else if(dire=="South"){
                dice[2]=up;
                up=dice[0];
                dice[0]=7-dice[2];
            }else if(dire=="West"){
                dice[3]=up;
                up=dice[1];
                dice[1]=7-dice[3];
            }else if(dire=="Right"){
                int t=dice[0];
                dice[0]=dice[3];
                dice[3]=dice[2];
                dice[2]=dice[1];
                dice[1]=t;
            }else{
                int t=dice[0];
                dice[0]=dice[1];
                dice[1]=dice[2];
                dice[2]=dice[3];
                dice[3]=t;
            }
            ans+=up;
            
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}