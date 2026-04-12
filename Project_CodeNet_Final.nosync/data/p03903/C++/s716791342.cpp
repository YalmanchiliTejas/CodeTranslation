            #include <bits/stdc++.h>
            #include<iostream>
            #include<cstdio>
            #include<vector>
            #include<queue>
            #include<map>
            #include<cstring>
            #include<string>
            #include <math.h>
            #include<algorithm>
        //    #include <boost/multiprecision/cpp_int.hpp>
            #include<functional>
          #define int long long
            #define inf  1000000007
            #define pa pair<int,int>
    #define ll long long
            #define pal pair<ll,ll>
            #define ppa pair<int,pa>
            #define  mp make_pair
            #define  pb push_back
            #define EPS (1e-10)
            #define equals(a,b) (fabs((a)-(b))<EPS)
     
            using namespace std;
     
            class Point{
            	public:
            	double x,y;
            	Point(double x=0,double y=0):x(x),y(y) {}
            	Point operator + (Point p) {return Point(x+p.x,y+p.y);}
            	Point operator - (Point p) {return Point(x-p.x,y-p.y);}
            	Point operator * (double a) {return Point(x*a,y*a);}
            	Point operator / (double a) {return Point(x/a,y/a);}
            	double absv() {return sqrt(norm());}
            	double norm() {return x*x+y*y;}
            	bool operator < (const Point &p) const{
            		return x != p.x ? x<p.x: y<p.y;
            	}
            	bool operator == (const Point &p) const{
            		return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
            	}
            };
            typedef Point Vector;
     
            struct Segment{
            Point p1,p2;
            };
     
        double hen(Vector a){
        if(fabs(a.x)<EPS && a.y>0) return acos(0);
        else if(fabs(a.x)<EPS && a.y<0) return 3*acos(0);
        else if(fabs(a.y)<EPS && a.x<0) return 2*acos(0);
        else if(fabs(a.y)<EPS && a.x>0) return 0.0;
        else if(a.y>0) return acos(a.x/a.absv());
        else return 2*acos(0)+acos(-a.x/a.absv());
     
        }
     
int gcd(int v,int b){
	if(v>b) return gcd(b,v);
	if(v==b) return b;
	if(b%v==0) return v;
	return gcd(v,b%v);
}
            double dot(Vector a,Vector b){
            	return a.x*b.x+a.y*b.y;
            }
            double cross(Vector a,Vector b){
            	return a.x*b.y-a.y*b.x;
            }
        
            //----------------kokomade tenpure------------

int par[100100],ranks[100100];     

void shoki(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		ranks[i]=0;
	}
}

int root(int x){
	return par[x]==x ? x : par[x]=root(par[x]);
}

bool same(int x,int y){
return root(x)==root(y);
}

void unite(int x,int y){
 x=root(x);
 y=root(y);
 if(x==y) return;
 if(ranks[x]<ranks[y]) par[x]=y;
 else {
	par[y]=x;
	if(ranks[x]==ranks[y]) ranks[x]=ranks[x]+1;
 }
}
int shiten;

vector<ppa> ve;
vector<pa> G[5000];
int omoi[4010][4010];


	void dfs(int ima,int mae,int omosa){
		omoi[shiten][ima]=omosa;
		for(int i=0;i<G[ima].size();i++){
			if(G[ima][i].first==mae) continue;
			dfs(G[ima][i].first,ima,max(omosa,G[ima][i].second));
		}
		return;
	} 

    signed  main(){
    	shoki(100000);
    	int n,m;
    	cin>>n>>m;
    	for(int i=0;i<m;i++){
    		int a,b,c;
    		cin>>a>>b>>c;
    		ve.pb(mp(c,mp(a,b)));
    		
    	}
    	int cnt=0;
    	int cost=0;
    	sort(ve.begin(),ve.end());
    	for(int i=0;i<m;i++){
    		pa zzz=ve[i].second;
    		
    		if(same(zzz.first,zzz.second)) continue;
    	    unite(zzz.first,zzz.second);
    		G[zzz.first].pb(mp(zzz.second,ve[i].first));
    		G[zzz.second].pb(mp(zzz.first,ve[i].first));
    		cost += ve[i].first;
    		cnt++;
    		if(cnt>=n-1) break;
    	}
    	
    	
    	for( shiten=1;shiten<=n;shiten++){
    		dfs(shiten,-1,0);
    	}	
    	
    	
    	int q;
    	cin>>q;
    	for(int i=0;i<q;i++){
    		int s,t;
    		cin>>s>>t;
    		cout<<cost-omoi[s][t]<<endl;
    	}

    //	printf("%.10f\n",ans);
    	return 0;
    }