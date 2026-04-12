 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
int N;
vector<int>v[100001];
bool used[100001];
bool ans=false;
int dfs(int x){
    used[x]=true;
    int count=0;
    REP(i,v[x].size()){
        if(used[v[x][i]]==false){
           int k=dfs(v[x][i]);
	   count+=k;
        }
    }
    if(count>=2){
       ans=true;
       count =0;
    }
    return 1-count;
}

int main(){
    cin>>N;
    int root=0;
    REP(i,100001){
        used[i]=false;
    }
    REP(i,N-1){
        int a,b;
        cin>>a;
        cin>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(N==2){
       cout<<"Second"<<endl;
       return 0;
    }
    REP(i,N){
        if(v[i].size()>1){
           root=i;
           break;
        }
    }
    
    int btk=1-dfs(root);
    if(btk==0){
       cout<<"First"<<endl;
       return 0;
    }
    if(ans==false){
       cout<<"Second"<<endl;
    }else{
       cout<<"First"<<endl;
    }
    return 0;
}