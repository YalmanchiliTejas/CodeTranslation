#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,i;
    cin>>n>>m;
    int point[n];//その点がどこにつながっているのかのフラグ
    for(i=0;i<n;i++)
    point[i]=0;
    int num = 0;
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        int c = a-1;
        int d = b-1;
        point[c]|=(1<<d);
        point[d]|=(1<<c);
    }
    stack<pair<int,int>>q;
    q.push(make_pair(0,1));//(注目点、行ったことがあるかのフラグ)
    while(q.empty()==false)
    {
        pair<int,int>tmp=q.top();
        q.pop();
        int current_position=tmp.first;
        int path=tmp.second;
        int checker=0;
        for(i=0;i<n;i++)
        {
            if(point[current_position]&(1<<i)&&!(path&(1<<i)))
            {
                int tmppath=path;
                tmppath|=(1<<i);
                q.push(make_pair(i,tmppath));
            }
            else if(path&(1<<i))
            checker++;
        }
        if(checker==n)
        num++;
    }
    cout<<num<<endl;
    return 0;
    
}
