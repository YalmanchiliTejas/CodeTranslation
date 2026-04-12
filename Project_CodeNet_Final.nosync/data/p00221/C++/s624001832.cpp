#include<bits/stdc++.h>
using namespace std;
int m,n;

void solve(){
    int x=m;
    int cur=0;

    bool no[10000]={0};
    for(int i=1;i<=n;i++){
        while(no[cur])cur=(cur+1)%m;
        string s;
        cin>>s;
        if(x<=1)continue;

        bool ok=true;
        if(i%3==0&&i%5==0){
            if(s!="FizzBuzz")ok=false;
        }
        else if(i%3==0){
            if(s!="Fizz")ok=false;
        }
        else if(i%5==0){
            if(s!="Buzz")ok=false;
        }
        else{
            stringstream ss;
            string d;
            ss<<i;
            ss>>d;
            if(s!=d)ok=false;
        }
        if(!ok){
            no[cur]=true;
            x--;
        }
        cur=(cur+1)%m;
    }

    bool flag=false;
    for(int i=0;i<m;i++)if(!no[i]){
        if(flag)cout<<" ";
        else flag=true;
        cout<<i+1;
    }
    cout<<endl;
}

int main(){
    while(cin>>m>>n,m||n)solve();
    return 0;
}