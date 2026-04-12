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

struct seg_rangeadd_getmin{
    //       1
    //   2        3
    // 4   5   6    7
     
     
    private:
    public:
     
    // (1<<15)=32768
    // 1<<16 = 65536
    // 1<<17 = 131072
    // 1<<18 = 262144
     
    int cor=(1<<18);
    int inff=inf*1000000ll;
     
    vector<int> vec;
    vector<int> lazy;
    void shoki1(){
        vec.resize(2*cor+3, 0);
        lazy.resize(2*cor+3, 0);
    }
    void shoki2(){
        //lazy[1]=(1ll<<31)-1;
        //初期値
    }
         
    void chien(int k,int l,int r){
        //if(lazy[k]==-1) return;
        if(l+1<r){
            vec[k]+=lazy[k];
            lazy[2*k]+=lazy[k];
            lazy[2*k+1]+=lazy[k];
            lazy[k]=0;
        }
        else {
            vec[k]+=lazy[k];
            lazy[k]=0;
        }
    }
     
    int rangeadd(int a,int b,int w, int k=1,int l=0,int r=-3){
        //[a,b)を wに変更
        if(r<0) r=cor;
         
        if(a<=l && r<=b){
            lazy[k]+=w;
            chien(k,l,r);
            return vec[k];
        }
        if(r<=a || b<=l){
            chien(k,l,r);
            return vec[k];
        }
         
        chien(k,l,r);
//  cout<<k<<" "<<l<<" "<<r<<endl;
        int w1=rangeadd(a,b,w,k*2,l,(l+r)/2);
        int w2=rangeadd(a,b,w,k*2+1,(l+r)/2,r);
        vec[k]=min(w1,w2);
        return vec[k];
    }
     
    // [a,b)
    // k-th node
    // k no kukanha [l,r)
     
    int getmin(int a,int b,int k=1,int l=0,int r=-1){
        //[a,b)のminを取得
        if(r<0) r=cor;
        chien(k,l,r);
        if(r<=a || b<=l){// 区間外
            return inff;
        }
         
        if(a<=l && r<=b){// 完全含む
             
            return vec[k];
        }
        int w1=getmin(a,b,k*2,l,(l+r)/2);
        int w2=getmin(a,b,k*2+1,(l+r)/2,r);
        return min(w1,w2);
    }
    void pre(){
        for(int i=1;i<2*cor;i++){
            cout<<vec[i]<<" ";
            if(((i+1)&(-(i+1)))==i+1) cout<<endl;
        }
    }
     
};
seg_rangeadd_getmin se;
vector<pa> ve[200020];
 signed main(){
 	

    	       cin.tie(0);
   			ios::sync_with_stdio(false);
 	se.shoki1();
 	se.shoki2();
 	
 	int n,m;
 	cin>>n>>m;
 	
 	for(int i=0;i<m;i++){
 		int y,yy,yyy;
 		cin>>y>>yy>>yyy;
 			ve[yy].pb({y,yyy});
 	}
 	
 	for(int i=1;i<=n;i++){
 		int e=se.getmin(0,i);
 		//e*=-1;
 		se.rangeadd(i,i+1,e);
 		for(auto v:ve[i]){
 			se.rangeadd(v.first,i+1,-v.second);
 		}
 	//j++) cout<<-se.getmin(j,j+1)<<" ";
 	//	cout<<endl;
 	}
 	
 	cout<<se.getmin(0,n+1)*-1<<endl;
 	return 0;
 	
  }

