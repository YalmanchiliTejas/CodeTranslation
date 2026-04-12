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
     
            double dot(Vector a,Vector b){
            	return a.x*b.x+a.y*b.y;
            }
            double cross(Vector a,Vector b){
            	return a.x*b.y-a.y*b.x;
            }
        
            //----------------kokomade temple------------
int n,x,k;
string s[10];
    signed main(){
  int h,w;
    	cin>>h>>w;
    	int y=0;
    	for(int i=0;i<h;i++){
    		cin>>s[i];
    		for(int j=0;j<w;j++){
    			if(s[i][j]=='#'){
    				y++;
    				
    			}
    			
    			
    		
    	}
    	}
    		
    		if(y!=h+w-1){
    			cout<<"Impossible"<<endl;
    			return 0;
    		}		
    //	cout<<"s"<<endl;
    	for(int i=0;i<h;i++){
    		for(int j=0;j<w;j++){
    			if(i==h-1 && j== w-1) continue;
    			if(s[i][j]=='#'){
    				if(!(s[i+1][j]=='#'||s[i][j+1]=='#')){
    					cout<<"Impossible"<<endl;
    			return 0;
    				}
    				
    			}
    			
    		}
    		
    	}
    	cout<<"Possible"<<endl;
    			return 0;
    	
    //	printf("%.10f\n",ans);
    	return 0;
    }