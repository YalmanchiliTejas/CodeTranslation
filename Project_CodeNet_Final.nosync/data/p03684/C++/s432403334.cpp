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
                            #define pal pair<double,int>
                            #define ppa pair<pa,int>
                            #define ppap pair<int,pa>
                            #define ssa pair<string,int>
                            #define  mp make_pair
                            #define  pb push_back
                            #define EPS (1e-10)
                            #define equals(a,b) (fabs((a)-(b))<EPS)
                     
                            using namespace std;
                     //priority_queue<int, vector<int>, greater<int> > que;
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
                     
                string itos( int i ) {
                ostringstream s ;
                s << i ;
                return s.str() ;
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
                        
                double distans(double x1,double y1,double x2,double y2){
                	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                	return sqrt(rr);
                	
                }
int pr[100010];
int inv[100010];
 
int beki(int wa,int rr){
	if(rr==0) return 1ll;
	if(rr==1) return wa;
	if(rr%2==1) return (beki(wa,rr-1)*wa)%inf;
	int zx=beki(wa,rr/2);
	return (zx*zx)%inf;
}
 
 
void gya(){
	pr[0]=1;
	for(int i=1;i<100010;i++){
		pr[i]=(pr[i-1]*i)%inf;
	}
	for(int i=0;i<100010;i++) inv[i]=beki(pr[i],inf-2);
	
}

                         //----------------kokomade tenpure------------
int par[200100],ranks[200100],kosuu[200100];     

void shoki(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		ranks[i]=0;
		kosuu[i]=1;
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
	int xx=kosuu[x],yy=kosuu[y];
 if(x==y) return;
	if(ranks[x]<ranks[y]){
		par[x]=y;
		kosuu[y]=yy+xx;
	}
 else {
	par[y]=x;
	if(ranks[x]==ranks[y]) ranks[x]=ranks[x]+1;
 	kosuu[x]=yy+xx;
 }
	return;
}
vector<ppap> ve; 
vector<ppa> ve1,ve2;
int a[100020][2];
signed main(){
int n,m;
cin>>n;
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	for(int i=0;i<n;i++){
		ve1.pb(mp(mp(a[i][0],a[i][1]),i));
		ve2.pb(mp(mp(a[i][1],a[i][0]),i));
	}
	sort(ve1.begin(),ve1.end());
	sort(ve2.begin(),ve2.end());
	
	for(int i=0;i<n-1;i++){
		ve.pb(mp(ve1[i+1].first.first-ve1[i].first.first,mp(ve1[i].second,ve1[i+1].second)));
		ve.pb(mp(ve2[i+1].first.first-ve2[i].first.first,mp(ve2[i].second,ve2[i+1].second)));
	//	cout<<
	}
	int ans=0;
	sort(ve.begin(),ve.end());
	shoki(100010);
	for(int i=0;i<ve.size();i++){
		
		if(same(ve[i].second.first,ve[i].second.second)) continue;
		unite(ve[i].second.first,ve[i].second.second);
		ans += ve[i].first;
		
		
	}
	cout<<ans<<endl;
	//shoki(100010);
	
	return 0;
}


