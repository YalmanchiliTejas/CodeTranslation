#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a,b,c,min,max,minc,maxc;
    lli cost1,cost,x,y;
    cin>>a>>b>>c>>x>>y;
    
    if(x<y){
        min=x;
        max=y;
        minc=a;
        maxc=b;
    }
    else{
        min=y;
        max=x;
        minc=b;
        maxc=a;
        
    }
    
    
     if(2*c*max <= 2*c*min+(max-min)*maxc){
            cost1=2*c*max;
        } 
        else 
        cost1=2*c*min+(max-min)*maxc;
        if(max*maxc+min*minc <= cost1)
            cost=max*maxc+min*minc;
        else cost=cost1;
        
        cout<<cost;
	return 0;
}
