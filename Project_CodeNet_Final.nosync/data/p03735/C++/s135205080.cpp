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
                                        #define pal pair<double,double>
                                        #define ppap pair<pa,int>
                                  
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-7)
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
                                        	bool operator > (const pa2 &p) const{
                                        		return x != p.x ? x>p.x: y>p.y;
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

int a[200020][2];
vector<pa3>ve;
int iti[200020][2];
set<int> se;
int use[400020]={0};
   signed main(){
        cin.tie(0);
    		ios::sync_with_stdio(false);
int n;
   	cin>>n;
   	
   	for(int i=0;i<n;i++){
   		int y,yy;
   		cin>>y>>yy;
   		if(y>yy) swap(y,yy);
   		a[i][0]=y;
   		a[i][1]=yy;
   			ve.pb((pa3){y,i,0});
   			ve.pb((pa3){yy,i,1});
   	}
   	sort(ve.begin(),ve.end());
   	for(int i=0;i<2*n;i++){
   		iti[ve[i].y][ve[i].z]=i;
   	}
   	if(ve[0].y==ve[2*n-1].y){
   //   cout<<ve[0].y<<endl;
   		int ma0=-inf,ma1=-inf,mi1=inf,mi0=inf;
   		for(int i=0;i<n;i++){
   			ma0=max(ma0,a[i][0]);
   			mi0=min(mi0,a[i][0]);
   			ma1=max(ma1,a[i][1]);
   			mi1=min(mi1,a[i][1]);
   		}
   	//	exit(1);
   		cout<<(ma0-mi0)*(ma1-mi1)<<endl;
   		
   		return 0;
   	}
  
   	
   	int s=ve[0].y,t=ve[2*n-1].y;
   	int ans=inf*1000000200ll;
   
   	if(1){
   		int ma0=-inf,ma1=-inf,mi1=inf,mi0=inf;
   		for(int i=0;i<n;i++){
   			ma0=max(ma0,a[i][0]);
   			mi0=min(mi0,a[i][0]);
   			ma1=max(ma1,a[i][1]);
   			mi1=min(mi1,a[i][1]);
   		}
   		ans=min((ma0-mi0)*(ma1-mi1),ans);
   
   	}
   
   	int gen=inf;
   	for(int i=0;i<n;i++){
   		if(i==s){
   			gen=min(gen,a[s][1]);
   			se.insert(a[s][1]);
   		}
   		else if(i==t){
   			gen=min(gen,a[t][0]);
   			se.insert(a[t][0]);
   		}
   		else{
   				gen=min(gen,a[i][1]);
   			se.insert(a[i][1]);
   			se.insert(a[i][0]);
   		}
   	}
   		
   	int dd=inf*1000000ll;
   	int ma=-inf,mi=inf;
   	int count=0;
   	for(int i=1;i<2*n-1;i++){
   		if(ve[i].y==s||ve[i].y==t){
   			use[i]=1;
   			ma=max(ma,ve[i].x);
   			mi=min(mi,ve[i].x);
   			count++;
   		}
   		else if(ve[i].z==0){
   		use[i]=1;
   			ma=max(ma,ve[i].x);
   			mi=min(mi,ve[i].x);
   			count++;
   		}
   	}
  // 	return 0;
 //  	if(count!=n) exit(1);
   	dd=ma-mi;
   	int hi=1;
  
   	for(auto it=se.begin();it!=se.end();it++){
   		
   		if(it==se.begin())continue;
   		if(*it>gen) break;
   		while(1){
          if(hi==2*n) break;
   			if(use[hi]==0){
   				hi++;
   				continue;
   			}
   			if(ve[hi].x>=*it) break;
   			use[hi]=0;
   			
   			use[iti[ve[hi].y][1]]=1;
   			ma=max(ma,a[ve[hi].y][1]);
   			hi++;
   		}
   	//	cout<<ma<<" "<<(*it)<<endl;
   		dd=min(dd,ma-*it);
   		
   		
   		
   		
   	}
   	ans=min(ans,dd*(a[t][1]-a[s][0]));
   	cout<<ans<<endl;
   	return 0;
        }