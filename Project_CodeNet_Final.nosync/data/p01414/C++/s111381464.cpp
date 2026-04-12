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
                           //    #define int long long
                                        #define inf  1000000007
                                        #define pa pair<int,int>
                                        #define ll long long
                                        #define pal pair<double,pa>
                                        #define ppap pair<pa,int>
                                  
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-10)
                                        #define equals(a,b) (fabs((a)-(b))<EPS)
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
                                        using namespace std;
                               			class pa3{
                                        	public:
                                        	int x,y,z;
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
                                        	double x;
                                        	int y,z,w;
                                        	pa4(double x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w) {}
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
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const pa2 &p) const{
                                        		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                        	}
                                        	bool operator != (const pa2 &p) const{
                                        		return !(abs(x-p.x)==0 && abs(y-p.y)==0);
                                        	}
                                        		
                                        
                                        };
                                        
                                               #define ppa pair<int,pas>
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
                            
   //         int pr[2000010];
     //       int inv[2000010];
            
            int beki(int wa,int rr,int warukazu){
            	if(rr==0) return 1ll;
            	if(rr==1) return wa%warukazu;
            	if(rr%2==1) return (beki(wa,rr-1,warukazu)*wa)%warukazu;
            	int zx=beki(wa,rr/2,warukazu);
            	return (zx*zx)%warukazu;
            }
            /*
			int comb(int nn,int rr){
				int r=pr[nn]*inv[rr];
				r%=inf;
				r*=inv[nn-rr];
				r%=inf;
				return r;
			}
            
            void gya(int ert){
            	pr[0]=1;
            	for(int i=1;i<ert;i++){
            		pr[i]=(pr[i-1]*i)%inf;
            	}
            	for(int i=0;i<ert;i++) inv[i]=beki(pr[i],inf-2,inf);
            	
            }
             */
			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            
             //sort(ve.begin(),ve.end(),greater<int>());
                                     //----------------kokomade tenpure------------
            //vector<double> ans(100000000),ans2(100000000);
 
int n;
string s[4];
int h[20],w[20];
int dp[1<<16];

queue<pa> pq;   
vector<pa> ve;
   signed main(){
cin>>n;
   	for(int i=0;i<n;i++)cin>>h[i]>>w[i];
   	for(int i=0;i<(1<<16);i++)dp[i]=-1;
   	for(int i=0;i<4;i++)cin>>s[i];
   	string ss="RBG";
   	
   	   	for(int k=0;k<n;k++){
   			for(auto c:ss)for(int i=1-h[k];i<4;i++)for(int j=1-w[k];j<4;j++){
   				int bit1=0,bit2=0;
   				for(int x=max(i,0);x<min(i+h[k],4);x++)for(int y=max(j,0);y<min(j+w[k],4);y++){
   					bit1 += (1<<((y)*4+x));
   					if(s[x][y]==c) bit2+=(1<<((y)*4+x));
   				
   				}
   				ve.pb(mp(bit1,bit2));
   			}
   		}
   	
   	
   	pq.push(mp(0,0));
   	while(pq.size()>0){
   		pa z=pq.front();
   		pq.pop();
   		if(dp[z.second]>=0) continue;
   		dp[z.second]=z.first;
   		if(z.second+1==(1<<16)){
   		cout<<z.first<<endl;
   			return 0;
   		}
   	//		cout<<bitset<16>(z.second)<<" "<<z.first <<endl;
   		for (auto v:ve){
   			int bit=(1<<16)-1;
   			bit ^= v.first;
   			bit= bit&z.second;
   			
   			bit=bit+v.second;
   			if(dp[bit]<0) pq.push(mp(z.first+1,bit));
   		}
   	}
   	
   	
   	cout<<dp[(1<<16)-1]<<endl;
   	
   	
   	
   	return 0;
        }
