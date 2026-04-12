#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second
#define MP make_pair
#define PB push_back
bool cmp(const pi &a,const pi &b){
    return a.S>b.S;
}
int main(){
    string s;
    pi temp;
    vector<pi> v;
    map<int,int> m;
    int now;
    while(getline(cin,s)){
        temp=MP(0,0);
        now=0;
        while(s[now]!=','){
            temp.F*=10;
            temp.F+=s[now++]-'0';
        }
        now++;
        while(now<s.size()){
            temp.S*=10;
            temp.S+=s[now++]-'0';
        }
        if(temp.F==0&&temp.S==0)break;
        else v.PB(temp);
    }
    sort(v.begin(),v.end(),cmp);
    now=1;
    m.insert(MP(v[0].F,now));
    for(int i=1;i<v.size();i++){
        if(v[i].S<v[i-1].S)now++;
        m.insert(MP(v[i].F,now));
    }
    while(cin>>now)printf("%d\n",m[now]);
}
