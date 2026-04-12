#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    using ull=unsigned long long;
    int n;
    cin>>n;
    int s[505], t[505];
    ull u[505], v[505];
    for(int i=0; i<n; i++) cin>>s[i];
    for(int i=0; i<n; i++) cin>>t[i];
    for(int i=0; i<n; i++) cin>>u[i];
    for(int i=0; i<n; i++) cin>>v[i];
    ull a[505][505]={};
    for(int k=0; k<64; k++){
        int x[505][505];
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) x[i][j]=-1;
        auto myon=[&](){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(x[i][j]) a[i][j]^=(1ull<<k);
                }
            }
        };
        int x0=0, x1=0, y0=0, y1=0;
        for(int i=0; i<n; i++){
            if(s[i]==0 && ((u[i]>>k)&1ull)){
                x1=1;
                for(int j=0; j<n; j++) x[i][j]=1;
            }
            if(s[i]==1 && ((u[i]>>k)&1ull)==0){
                x0=1;
                for(int j=0; j<n; j++) x[i][j]=0;
            }
        }
        for(int j=0; j<n; j++){
            if(t[j]==0 && ((v[j]>>k)&1ull)){
                y1=1;
                for(int i=0; i<n; i++){
                    if(x[i][j]==0){
                        cout<<-1<<endl;
                        return 0;
                    }
                    x[i][j]=1;
                }
            }
            if(t[j]==1 && ((v[j]>>k)&1ull)==0){
                y0=1;
                for(int i=0; i<n; i++){
                    if(x[i][j]==1){
                        cout<<-1<<endl;
                        return 0;
                    }
                    x[i][j]=0;
                }
            }
        }
        if((x0 && x1) || (y0 && y1)){
            for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(x[i][j]==-1){
						if(x0 && x1){
							x[i][j]=s[i];
						}else{
							x[i][j]=t[j];
						}
					}
				}
			}
            myon(); continue;
        }
        if(x0 && y0){
            for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(x[i][j]==-1) x[i][j]=1;
            myon(); continue;
        }
        if(x1 && y1){
            for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(x[i][j]==-1) x[i][j]=0;
            myon(); continue;
        }
        int z0=0, z1=0, w0=0, w1=0;
        for(int i=0; i<n; i++){
            if(s[i]==0 && ((u[i]>>k)&1ull)==0){
                z0=1;
            }
            if(s[i]==1 && ((u[i]>>k)&1ull)){
                z1=1;
            }
        }
        for(int j=0; j<n; j++){
            if(t[j]==0 && ((v[j]>>k)&1ull)==0){
                w0=1;
            }
            if(t[j]==1 && ((v[j]>>k)&1ull)){
                w1=1;
            }
        }
        if(!x0 && !x1 && !y0 && !y1){
            if(z0!=z1 && w0!=w1 && z0!=w0){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(i==j) x[i][j]=1;
                        else x[i][j]=0;
                    }
                }
            }else if(z0 && z1){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(s[i]==0) x[i][j]=0;
                        else x[i][j]=1;
                    }
                }
            }else if(w0 && w1){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(t[j]==0) x[i][j]=0;
                        else x[i][j]=1;
                    }
                }
            }else if(z0){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        x[i][j]=0;
                    }
                }
            }else{
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        x[i][j]=1;
                    }
                }
            }
            myon(); continue;
        }
        if(z0 && z1){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(x[i][j]==-1 && s[i]==0) x[i][j]=0;
                    else if(x[i][j]==-1 && s[i]==1) x[i][j]=1;
                }
            }
            myon(); continue;
        }
        if(w0 && w1){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(x[i][j]==-1 && t[j]==0) x[i][j]=0;
                    else if(x[i][j]==-1 && t[j]==1) x[i][j]=1;
                }
            }
            myon(); continue;
        }
        if((z0 && x1) || (w0 && y1)){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++) if(x[i][j]!=1) x[i][j]=0;
            }
            myon(); continue;
        }
        if((z1 && x0) || (w1 && y0)){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++) if(x[i][j]!=0) x[i][j]=1;
            }
            myon(); continue;
        }
        if((w1 && x1) || (w0 && x0)){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(x[i][j]==-1 && s[i]==1) x[i][j]=1;
                    else if(x[i][j]==-1 && s[i]==0) x[i][j]=0;
                }
            }
            myon(); continue;
        }
        if((z1 && y1) || (z0 && y0)){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(x[i][j]==-1 && t[j]==1) x[i][j]=1;
                    else if(x[i][j]==-1 && t[j]==0) x[i][j]=0;
                }
            }
            myon(); continue;
        }
        int z=0;
        if(x1 || y1) z=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(x[i][j]==-1){
                    if(i==j) x[i][j]=z;
                    else x[i][j]=(z^1);
                }
            }
        }
        myon();
    }
    for(int i=0; i<n; i++){
        ull c=a[i][0];
        for(int j=1; j<n; j++){
            if(s[i]==0) c&=a[i][j];
            else c|=a[i][j];
        }
        if(c!=u[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int j=0; j<n; j++){
        ull c=a[0][j];
        for(int i=1; i<n; i++){
            if(t[j]==0) c&=a[i][j];
            else c|=a[i][j];
        }
        if(c!=v[j]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
	return 0;
}
