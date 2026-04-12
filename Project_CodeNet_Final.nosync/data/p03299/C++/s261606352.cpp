     #include <bits/stdc++.h>

//    #include <boost/multiprecision/cpp_int.hpp>
 #define int long long
 #define inf  1000000007
 #define pa pair<int,int>
 #define ll long long
 #define pal pair<double,double>
 #define ppap pair<pa,int>
  #define PI 3.14159265358979323846
  #define paa pair<int,char>
  #define  mp make_pair
  #define  pb push_back
  #define EPS (1e-10)
                                          
    int dx[8]={0,1,0,-1,1,1,-1,-1};
    int dy[8]={1,0,-1,0,-1,1,1,-1};
                                            using namespace std;
                                   			class pa3{
                                            	public:
                                            	int x;
                                   				int y,z;
                                            	pa3(int x=0,int y=0,int z=0):x(x),y(y),z(z) {}
                                            	bool operator < (const pa3 &p) const{
                                            		if(x!=p.x) return x<p.x;
                                            		if(y!=p.y) return y<p.y;
                                            		 return z<p.z;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                   				bool operator > (const pa3 &p) const{
                                            		if(x!=p.x) return x>p.x;
                                            		if(y!=p.y) return y>p.y;
                                            		 return z>p.z;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa3 &p) const{
                                            		return x==p.x && y==p.y && z==p.z;
                                            	}
                                            		bool operator != (const pa3 &p) const{
                                            			return !( x==p.x && y==p.y && z==p.z);
                                            	}
                                            
                                            };
                                            
                                            class pa4{
                                            	public:
                                            	int x;
                                            	int y,z,w;
                                            	pa4(int x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w) {}
                                            	bool operator < (const pa4 &p) const{
                                            		if(x!=p.x) return x<p.x;
                                            		if(y!=p.y) return y<p.y;
                                            		if(z!=p.z)return z<p.z;
                                            		return w<p.w;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator > (const pa4 &p) const{
                                            		if(x!=p.x) return x>p.x;
                                            		if(y!=p.y) return y>p.y;
                                            		if(z!=p.z)return z>p.z;
                                            		return w>p.w;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa4 &p) const{
                                            		return x==p.x && y==p.y && z==p.z &&w==p.w;
                                            	}
                                            		
                                            
                                            };
                                            class pa2{
                                            	public:
                                            	int x,y;
                                            	pa2(int x=0,int y=0):x(x),y(y) {}
                                            	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}
                                            	pa2 operator - (pa2 p) {return pa2(x-p.x,y-p.y);}
                                            	bool operator < (const pa2 &p) const{
                                            		return y != p.y ? y<p.y: x<p.x;
                                            	}
                                            	bool operator > (const pa2 &p) const{
                                            		return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa2 &p) const{
                                            		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                            	}
                                            	bool operator != (const pa2 &p) const{
                                            		return !(abs(x-p.x)==0 && abs(y-p.y)==0);
                                            	}
                                            		
                                            
                                            };
                                            
/*
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
                                     #define pl pair<int,pas>
                                            struct Segment{
                                            Point p1,p2;
                                            };
                                             double dot(Vector a,Vector b){
                                            	return a.x*b.x+a.y*b.y;
                                            }
                                            double cross(Vector a,Vector b){
                                            	return a.x*b.y-a.y*b.x;
                                            }
                                        
                bool parareru(Point a,Point b,Point c,Point d){
                //	if(abs(cross(a-b,d-c))<EPS)cout<<"dd "<<cross(a-b,d-c)<<endl;
                	return abs(cross(a-b,d-c))<EPS;
                }
                double distance_ls_p(Point a, Point b, Point c) {
                  if ( dot(b-a, c-a) < EPS ) return (c-a).absv();
                  if ( dot(a-b, c-b) < EPS ) return (c-b).absv();
                  return abs(cross(b-a, c-a)) / (b-a).absv();
                }
                bool is_intersected_ls(Segment a,Segment b) {
                	if(a.p1==b.p1||a.p2==b.p1||a.p1==b.p2||a.p2==b.p2) return false;
                	if(parareru((a.p2),(a.p1),(a.p1),(b.p2))&&parareru((a.p2),(a.p1),(a.p1),(b.p1))){
                //		cout<<"sss"<<endl;
                		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
                		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
                		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
                		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
                		return false;
                	}
                  else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
                }
                 
                double segment_dis(Segment a,Segment b){
                	if(is_intersected_ls(a,b))return 0;
                	double r=distance_ls_p(a.p1, a.p2, b.p1);
                	r=min(r,distance_ls_p(a.p1, a.p2, b.p2));
                	r=min(r,distance_ls_p(b.p1, b.p2, a.p2));
                	r=min(r,distance_ls_p(b.p1, b.p2, a.p1));
                	return r;
                }
                Point intersection_ls(Segment a, Segment b) {
                  Point ba = b.p2-b.p1;
                  double d1 = abs(cross(ba, a.p1-b.p1));
                  double d2 = abs(cross(ba, a.p2-b.p1));
                  double t = d1 / (d1 + d2);
                 
                  return a.p1 + (a.p2-a.p1) * t;
                }
 */                
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
                 
                                double distans(double x1,double y1,double x2,double y2){
                                	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                                	return sqrt(rr);
                                	
                                }
                                int mod;
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
pa operator+(const pa & l,const pa & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
                                
                int pr[1000010];
                int inv[1000010];
                
                int beki(int wa,int rr,int warukazu){
                	if(rr==0) return 1%warukazu;
                	if(rr==1) return wa%warukazu;
                	wa%=warukazu;
                	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
                	ll zx=beki(wa,rr/2,warukazu);
                	return (zx*zx)%warukazu;
                }
    double bekid(double w,int r){
    	if(r==0) return 1.0;
    	if(r==1) return w;
    	if(r%2) return bekid(w,r-1)*w;
    	double f=bekid(w,r/2);
    	return f*f;
    }
                
    			int comb(int nn,int rr){
    				int r=pr[nn]*inv[rr];
    				r%=mod;
    				r*=inv[nn-rr];
    				r%=mod;
    				return r;
    			}
                
                void gya(int ert){
                	pr[0]=1;
                	for(int i=1;i<ert;i++){
                		pr[i]=(pr[i-1]*i)%mod;
                	}
                	for(int i=0;i<ert;i++) inv[i]=beki(pr[i],mod-2,mod);
                	
                }
                
              //   cin.tie(0);
    		//	ios::sync_with_stdio(false);
    			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            
                 //sort(ve.begin(),ve.end(),greater<int>());
    
       
       
                               //----------------kokomade tenpure------------



int a[110];

pa dfs(int l,int r,int h){
	int mi=inf*100000ll;
	int mk=0;
	for(int  i=l;i<r;i++){
		if(a[i]<mi){
			mi=a[i];
			mk=1;
		}
		else if(a[i]==mi)mk++;
	}
	assert(mk>0);
	if(mk==r-l){
		int ta=mi-h;
	//	cout<<ta<<endl;
		assert(ta>0);
			return {beki(2,ta-1,inf),(beki(2,r-l,inf)+inf-2)%inf};
	}
	
	vector<pa> kukan,tugi;
	
	int f=0,s=0;
	for(int i=l;i<r;i++)if(a[i]!=mi){
		if(kukan.size()==0){
				kukan.pb({i,i});
		}
		else if(kukan.back().second==i-1){
			kukan.back().second++;
		}
		else{
				kukan.pb({i,i});
		}
	}
	f=beki(2,mi-h-1,inf);
	for(auto &e:kukan){
		e.second++;
		tugi.pb(dfs(e.first,e.second,mi));
	}
	
	for(auto e:tugi){
	//	cout<<e.first<<" "<<e.second<<endl;
		f*=e.first*2%inf;
		f%=inf;
	}
	s=1;
	int y=kukan.size();
	for(int i=0;i<y;i++){
		int kirei=2*(beki(2,r-l-(kukan[i].second-kukan[i].first),inf)+inf)%inf;
		int dame=(beki(2,kukan[i].second-kukan[i].first,inf)-2+inf)%inf*beki(2,r-l-(kukan[i].second-kukan[i].first),inf)%inf;
	//	cout<<"ki "<<kirei<<" dame "<<dame<<endl;
		assert((kirei+dame)%inf==(beki(2,r-l,inf)+inf)%inf);
		
		int kake1=kirei*tugi[i].first*2%inf;
		int kake2=beki(2,r-l-(kukan[i].second-kukan[i].first),inf)%inf*tugi[i].second%inf;
	//	cout<<kake1<<" "<<kake2<<endl;
		s*=(kake1+kake2)%inf*beki((beki(2,r-l,inf)+inf),inf-2,inf)%inf;
		s%=inf;
	}
	s*=(beki(2,r-l,inf)+inf)%inf;
	
	int hiku=2;
	for(auto e:tugi){
	//	cout<<e.first<<" "<<e.second<<endl;
		hiku*=e.first*2%inf;
		hiku%=inf;
	}
	s%=inf;
	s+=inf-hiku;
	return {f,s%inf};
}

 signed main(){
 	

    	       cin.tie(0);
   			ios::sync_with_stdio(false);

 	int n;
cin>>n;
 	
 	for(int i=0;i<n;i++)cin>>a[i];
 	
 	pa z=dfs(0,n,0);
 	
 //	cout<<z.first<<" "<<z.second<<endl;
 	
 	int ans=2*z.first%inf;
 //	z.second*=(beki(2,n,inf)+inf-2)%inf;
 	z.second%=inf;
 	cout<<(ans+z.second)%inf<<endl;
 	return 0;
 	
  }

