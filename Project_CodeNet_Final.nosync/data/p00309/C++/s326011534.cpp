#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <utility>
using namespace std;
const int MOD=1e9+7;
const int N=1e2+10;
int p[N];
int find(int n){
    return p[n]==n?n:p[n]=find(p[n]);
}
struct side{
    int from;
    int to;
    int length;
    void in(){
        scanf("%d%d%d",&from,&to,&length);
        return ;
    }
    void pull(){
        from=find(from);
        to=find(to);
        return ;
    }
    bool out(){
        return from==to;
    }
    void operator =(side a){
        from=a.from;
        to=a.to;
        length=a.length;
        return ;
    }
};
struct cmp{
    bool operator ()(const side& a,const side& b){
        return a.length>b.length;
    }
};
struct matrix{
    int size;
    vector<vector<int>> v;
    void init(int n){
        v.clear();
        size=n;
        vector<int> emp;
        emp.clear();
        for(int i=0;i<n;i++){
            v.push_back(emp);
            for(int j=0;j<n;j++)v.back().push_back(0);
        }
        return ;
    }
};
set<int> graph[N],ng[N],ins;
int n,size[N],ns=0;
long long int ans=0;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
    return ;
}
long long int gcd(long long int a,long long int b){
    if(b==0)return a;
    return gcd(b,a%b)%MOD;
}
long long int pow(long long int a,int t){
    if(t==0)return 1;
    long long int temp=pow(a,t/2);
    temp*=temp;
    temp%=MOD;
    if(t&1){
        temp*=a;
        temp%=MOD;
    }
    return temp;
}
long long int rev(long long int a){
    return pow(a,MOD-2);
}
long long int det(matrix &m){
    long long int temp=1,piv,mul;
    for(int i=0;i<m.size;i++){
        if(m.v[i][i]==0){
            for(int j=i+1;j<m.size;j++)if(m.v[j][i]!=0){
                for(int k=i;k<m.size;k++)swap(m.v[j][k],m.v[i][k]);
                break;
            }
        }
        for(int j=i+1;j<m.size;j++)if(m.v[j][i]!=0){
            piv=m.v[i][i]/gcd(m.v[i][i],m.v[j][i]);
            mul=m.v[j][i]/gcd(m.v[i][i],m.v[j][i]);
            for(int k=i;k<m.size;k++)m.v[j][k]=(m.v[j][k]*piv-m.v[i][k]*mul)%MOD;
            temp*=rev(piv);
            temp%=MOD;
        }
    }
    for(int i=0;i<m.size;i++){
        temp*=m.v[i][i];
        temp%=MOD;
    }
    return temp;
}
long long int lap(set<int>& s){
    matrix m;
    map<int,int> ma;
    int now=0;
    for(int i=1;i<=n;i++)if(s.find(find(i))!=s.end())ma.insert({i,now++});
    if(ma.size()==1)return 1;
    m.init((int)ma.size());
    for(pair<int,int> i:ma){
        for(int j:graph[i.first]){
            if(ma.find(j)!=ma.end()){
                m.v[i.second][i.second]++;
                m.v[i.second][ma[j]]=-1;
            }
        }
    }
    for(int i=0;i<m.size;i++)m.v[i][0]=m.v[0][i]=0;
    m.v[0][0]=1;
    return det(m);
}
void dfs(int now){
    if(now>n){
        if(!ins.empty()){
            queue<int> q;
            set<int> in=ins,left,right;
            int temp;
            q.push(*in.begin());
            in.erase(in.begin());
            while(!q.empty()){
                temp=q.front();
                q.pop();
                for(int i:ng[temp]){
                    if(in.find(i)!=in.end()){
                        in.erase(i);
                        q.push(i);
                    }
                }
            }
            if(in.empty()){
                for(int i=1;i<=n;i++)if(p[i]==i&&ins.find(i)==ins.end())in.insert(i);
                if(!in.empty()){
                    q.push(*in.begin());
                    in.erase(in.begin());
                    while(!q.empty()){
                        temp=q.front();
                        q.pop();
                        for(int i:ng[temp]){
                            if(in.find(i)!=in.end()){
                                in.erase(i);
                                q.push(i);
                            }
                        }
                    }
                    if(in.empty()){
                        for(int i=1;i<=n;i++)if(p[i]==i){
                            if(ins.find(i)==ins.end())left.insert(i);
                            else right.insert(i);
                        }
                        ans+=(lap(left)*lap(right))%MOD;
                        ans%=MOD;
                    }
                }
            }
        }
        return ;
    }
    if(p[now]==now){
        ins.insert(now);
        ns+=size[now];
        dfs(now+1);
        ins.erase(now);
        ns-=size[now];
    }
    dfs(now+1);
    return ;
}
int main(){
    int m,now,in,l,r;
    side temp,s[N*N];
    priority_queue<side,vector<side>,cmp> pq;
    scanf("%d%d",&n,&m);
    in=n;
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=0;i<m;i++){
        temp.in();
        s[i]=temp;
        graph[temp.from].insert(temp.to);
        graph[temp.to].insert(temp.from);
        pq.push(temp);
    
    }
    now=pq.top().length;
    while(in>1){
        temp=pq.top();
        now=temp.length;
        pq.pop();
        temp.pull();
        if(!temp.out()){
            p[temp.from]=temp.to;
            in--;
        }
        while(!pq.empty()){
            if(pq.top().length<=now){
                temp=pq.top();
                pq.pop();
                temp.pull();
                if(!temp.out()){
                    p[temp.from]=temp.to;
                    in--;
                }
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++){
        p[i]=i;
        size[i]=0;
    }
    for(int i=0;i<m;i++)if(s[i].length<now){
        s[i].pull();
        p[s[i].from]=s[i].to;
    }
    for(int i=1;i<=n;i++){
        l=find(i);
        size[l]++;
        for(int j:graph[i]){
            r=find(j);
            if(l!=r){
                ng[l].insert(r);
                ng[r].insert(l);
            }
        }
    }
    dfs(1);
    if(ans<0){
        ans%=MOD;
        ans+=MOD;
    }
    printf("%d %lld\n",now,ans%MOD);
}
