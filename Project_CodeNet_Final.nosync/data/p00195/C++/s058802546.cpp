#include <bits/stdc++.h>
using namespace std;
int main(){
    bool flag =true;
    while(flag){
        priority_queue<pair<int,char> > data;
        while(!data.empty())data.pop();
        for(int i='A';i <='E';i++){
            int x,y;
            cin>>x>>y;
            int sum =x+y;
            if(sum==0){
                flag =false;
                break;
            }
            data.push(make_pair(sum,i));
        }
        if(flag)
            cout <<data.top().second<<" "<<data.top().first<<endl;
    }
    return 0;
}