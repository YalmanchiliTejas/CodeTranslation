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
            #define mod  1000000007
            #define pa pair<int,int>
            #define ll long long
            #define pal pair<double,int>
            #define ppa pair<int,pa>
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
 
int beki(int a, int r){
	if(r==0)return 1;
	if(r==1) return a%mod; 
	if(r%2==1){
		int y=beki(a,r-1);
		return(y*a)%mod;
		
	}
	int yy=beki(a,r/2);
	return (yy*yy)%mod;
}
 
 int inf=mod*2;
 
 int kai[100000];
 int inv[100000];
int memo[1004][1004]={0};
            //----------------kokomade tenpure------------
int n,a,b,c,d,ans=0;

int ic(int u,int v){
	return v*(v+1)/2-u*(u+1)/2;
}
int comb(int k,int r){
	if(k==0)return 1;
	int z=kai[k]*inv[r];
	z%=mod;
	z *= inv[k-r];
	return z%mod;
	
}
int cou=0;
void saiki(int nokori,int nin,int u){
	cou++;
//	cout<<nokori<<" "<<nin<<" "<<u<<endl;
	if(nin==a-1 && nokori!=0)return;
	if(u==0) return;
	if(nin==a-1){
		ans +=u;
	//	cout<<u<<endl;
		return;
	}
	
	if(nokori > d* ic(a-1,nin))return;
	
	saiki(nokori,nin-1,u);
	for(int i=c;i<=d;i++){
		if(nin*i<=nokori){
			int uu=u;
			uu *= comb(nokori,nin*i);
			uu%=mod;
		//	if(nokori==1000 && nin==1&& i==1)cout<<u<<" uu="<<comb(nokori,nin*i)<<endl;
			for(int j=0;j<i;j++){
				uu *= comb(nin*(i-j),nin);
				uu %=mod;
			}
			uu*=inv[i];
			uu%=mod;
			
			saiki(nokori-nin*i,nin-1,uu);
			
		}
		
		
	}
	return;
	
}
    signed  main(){
    	kai[0]=1;
    	for(int i=1;i<100000;i++)kai[i]=(i*kai[i-1])%mod;
    	for(int i=0;i<100000;i++){
    		inv[i]=beki(kai[i],mod-2)%mod;
    	}
    	
    	
    	
	cin>>n>>a>>b>>c>>d;
    	
    	
    	for(int i=a-1;i<=b;i++)for(int j=0;j<=1000;j++){
    		
    		int u=1;
    		if(i==a-1 && j==0)memo[a-1][0]=1;
    		else if(i>a-1){
    			
    			memo[i][j] += memo[i-1][j];
    			for(int k=c;k<=d;k++){
    				if(j< i*k) break;
    				int u=kai[n-j+i*k];
    				u *= inv[n-j];
    				u%=mod;
    				u*= beki(inv[i],k);
    				u%=mod;
    				
					
    				u*=inv[k];
					u%=mod;
    				memo[i][j] += (memo[i-1][j-i*k]*u)%mod;
    			}
    			
    		}
    		memo[i][j]%=mod;
    	}
    	
    
    	cout<<memo[b][n]%mod<<endl;
    	return 0;
    }
    //printf("%d %.10f %.10f\n",i,xx/ri,yy/ri);