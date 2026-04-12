#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    pair<long long,int> *px,*py;
    vector<pair<long long,int>> *edge;
    px=new pair<long long,int>[N];
    py=new pair<long long,int>[N];
    edge=new vector<pair<long long,int>>[N];

    for(int i=0;i<N;i++){
        long long x,y;
        cin >> x >> y;
        px[i]=make_pair(x,i);
        py[i]=make_pair(y,i);
    }
    sort(px,px+N);
    sort(py,py+N);

    for(int i=1;i<N;i++){
        int a=px[i-1].second,b=px[i].second;
        long long c=px[i].first-px[i-1].first;
        edge[a].push_back(make_pair(c,b));
        edge[b].push_back(make_pair(c,a));

        a=py[i-1].second; b=py[i].second;
        c=py[i].first-py[i-1].first;
        edge[a].push_back(make_pair(c,b));
        edge[b].push_back(make_pair(c,a));
    }

    long long d=0;
    bool *chk;
    chk=new bool[N];
    for(int i=0;i<N;i++) chk[i]=false;

    priority_queue<pair<long long,int>> Q;
    chk[0]=true;
    for(auto e : edge[0]){
        Q.push(make_pair(-e.first,e.second));
    }

    while(!Q.empty()){
        auto t=Q.top();
        Q.pop();

        if(chk[t.second]) continue;
        d-=t.first;
        chk[t.second]=true;
        for(auto e : edge[t.second]){
            Q.push(make_pair(-e.first,e.second));
        }
    }

    cout << d << endl;
    
    delete[] px,py,edge,chk;
    return 0;
}