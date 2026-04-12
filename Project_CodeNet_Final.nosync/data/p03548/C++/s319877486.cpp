#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
pair<int,int> p;
map<int,int> m;
deque<int> d;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int x,y,z;
cin>>x>>y>>z;
int i=0;
while(x>=y+z ){
    if(i==0)
        x-=z;
        x-=(y+z);
        i++;
    }

cout<<i<<endl;
return 0;
}
