#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<=(end);i++)
#define REP(i, n) FOR(i,1,n)
#define IFOR(i, begin, end) for(int i=(end);i>=(begin);i--)
#define IREP(i, n) IFOR(i,1,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())

#define ll long long
using namespace std;

bool is_prime(int k)
{
    for(int j=2;j*j<=k;j++){
        if(k%j==0) {
            return false;
        }
    }
    return true;
}

int main()
{
	stringstream ss;
    // 入力
    int H,W;
    cin>>H>>W;
    string a[H+1];
    REP(i,H){
    	cin>>a[i];
    }

    bool yoko[W+1];
    bool tate[H+1];
    bool oped=false;
    while(1){
    	bool oped=false;
	    REP(i,H){
	    	yoko[i]=true;
	    	REP(j,W){
	    		if(a[i][0]=='#') yoko[i]=false;
	    		if(a[i][j-1]!=a[i][0]) yoko[i]=false;
	    	}
	    	if(yoko[i]){
	    		oped=true;
	    		FOR(k,i,H-1){
	    			a[k]=a[k+1];
	    		}
	    		H--;
	    	}
	    }

	    REP(i,W){
	    	tate[i]=true;
	    	REP(j,H){
	    		if(a[1][i-1]=='#') tate[i]=false;
	    		if(a[j][i-1]!=a[1][i-1]) tate[i]=false;
	    	}
	    	if(tate[i]){
	    		oped=true;
	    		FOR(k,1,H){
	    			FOR(l,i,W-1){
	    				a[k][l-1]=a[k][l];
	    			}
	    			a[k].pop_back();
	    		}
	    		W--;
	    	}
	    }
	    if(!oped){
	    	REP(i,H){
	    		cout<<a[i]<<endl;
	    	}
	    	return 0;
	    }
	}
    return 0;
}