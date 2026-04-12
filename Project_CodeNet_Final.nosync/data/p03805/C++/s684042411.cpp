#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
#include<set>

using namespace std;
#define SAY_YES cout<<"YES"<<endl;
#define SAY_Yes cout<<"Yes"<<endl;
#define SAY_NO cout<<"NO"<<endl;
#define SAY_No cout<<"No"<<endl;
#define IFYES(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;} 
#define IFYes(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;} 
#define IFyes(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"yes"<<endl;}else{cout<<"no"<<endl;} 
typedef pair<long long int,long long int> pll;


const long long int mod=1000000007;
const long long int INF=99999999999999999;



long long int N,M,a[100],b[100],tmp[10]={2,3,4,5,6,7,8,9},res=0;
bool edge[10][10]={};
int main() {
	cout << fixed << setprecision(18);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>a[i]>>b[i];
        edge[a[i]][b[i]]=true;
        edge[b[i]][a[i]]=true;
    }
    do{
        for(int i=0;i<=N-2;i++){
            //cout<<tmp[i]<<" ";
            //if(!edge[tmp[i]][tmp[i+1]]&&!edge[tmp[i+1]][tmp[i]]){continue;}
        }
        //cout<<endl;
        if(!edge[1][tmp[0]]&&!edge[tmp[0]][1]){continue;}
        for(int i=0;i<=N-3;i++){
            
            if(!edge[tmp[i]][tmp[i+1]]&&!edge[tmp[i+1]][tmp[i]]){res--;break;}
        }
        res++;
    }while(next_permutation(tmp,tmp+N-1));
    cout<<res<<endl;
} 
