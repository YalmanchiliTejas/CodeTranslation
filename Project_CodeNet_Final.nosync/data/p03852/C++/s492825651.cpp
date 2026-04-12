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
}

int par2[200100],ranks2[200100],kosuu2[200100];     

void shoki2(int n){
	for(int i=0;i<n;i++){
		par2[i]=i;
		ranks2[i]=0;
		kosuu2[i]=1;
	}
}

int root2(int x){
	return par2[x]==x ? x : par2[x]=root2(par2[x]);
}

bool same2(int x,int y){
return root2(x)==root2(y);
}

void unite2(int x,int y){
 x=root2(x);
 y=root2(y);
	int xx=kosuu2[x],yy=kosuu2[y];
 if(x==y) return;
	if(ranks2[x]<ranks2[y]){
		par2[x]=y;
		kosuu2[y]=yy+xx;
	}
 else {
	par2[y]=x;
	if(ranks2[x]==ranks2[y]) ranks2[x]=ranks2[x]+1;
 	kosuu2[x]=yy+xx;
 }
}
map<pa,int> se;
    signed  main(){
string s;
    	cin>>s;
    	if(s=="o"||s=="e"||s=="u"||s=="i"||s=="a") cout<<"vowel"<<endl;
    	else cout<<"consonant"<<endl;
    	
  //  	printf("%.10f\n",ans[n-1]);
    	return 0;
    }