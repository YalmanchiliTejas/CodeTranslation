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
                                        #define pal pair<double,pa>
                                        #define ppa pair<int,int>
                                        #define ppap pair<int,pa>
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-12)
                                        #define equals(a,b) (fabs((a)-(b))<EPS)
                                  #define VI vector<int>
                                        using namespace std;
                                        
                                  class pas{
                                    	public:
                                    	int x,y;
                                    	pas(int x=0,int y=0):x(x),y(y) {}
                                    	pas operator + (pas p) {return pas(x+p.x,y+p.y);}
                                    	pas operator - (pas p) {return pas(x-p.x,y-p.y);}
                                    	pas operator * (int a) {return pas(x*a,y*a);}
                                    	pas operator / (int a) {return pas(x/a,y/a);}
                                    //	double absv() {return sqrt(norm());}
                                    	int norm() {return x*x+y*y;}
                                    	bool operator < (const pas &p) const{
                                   		return x != p.x ? x<p.x: y<p.y;
                                   	}
                                  //		bool operator < (const pas &p) const{
                                    //		return y != p.y ? y<p.y: x<p.x;
                                    //	}
                                    	bool operator == (const pas &p) const{
                                    		return x==p.x && y==p.y;
                                    	}
                                    };

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
                                        
struct star{
Segment se[5];
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
            	if(parareru((a.p2),(a.p1),(b.p1),(b.p2))&&parareru((a.p2),(a.p1),(b.p1),(b.p1))){
            //		cout<<"sss"<<endl;
            		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
            		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
            		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
            		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
            		return false;
            	}
              else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
            }
            double segment_len(Segment a){
            	
            	return (a.p1-a.p2).absv();
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
			pair<Point,Point> circle_intersection(Point c1,double r1,Point c2,double r2){
				double d=(c1-c2).absv();
				double h=(r1*r1-r2*r2+d*d)/2.0/d;
				double l=sqrt(r1*r1-h*h);
			//	cout<<d<<" "<<h<<" "<<l<<endl;
				Point asi=c1+(c2-c1)*h/((c2-c1).absv());
				Vector r1r2=(c2-c1)/((c2-c1).absv());
				Vector sui={r1r2.y,-r1r2.x};
			//	cout<<sui.x<<" "<<sui.y<<endl;
				pair<Point,Point> z=mp(asi+sui*l,asi-sui*l);
				if(z.first.x>z.second.x) swap(z.first,z.second);
				return z;
			}
double dist(star s1,star s2){
	double ans=10000000000.0;
	
	for(int i=0;i<5;i++)for(int j=0;j<5;j++){
		if( is_intersected_ls(s1.se[i],s2.se[j])) {
			
//			cout<<s1.se[i].p1.x<<" "<<s1.se[i].p1.y<<endl;
//			cout<<s1.se[i].p2.x<<" "<<s1.se[i].p2.y<<endl;
//			cout<<s2.se[j].p1.x<<" "<<s2.se[j].p1.y<<endl;
//			cout<<s2.se[j].p2.x<<" "<<s2.se[j].p2.y<<endl;
		return 0.0;
		}
		ans=min(ans,segment_dis(s1.se[i],s2.se[j]));
//		cout<<"   "<<i<<" "<<j<<" "<<segment_dis(s1.se[i],s2.se[j])<<endl;
	}
	return ans;
}

int a[160][160]={0};
int ans;
int ddx[6]={1,0,-1,-1,0,1};
int ddy[6]={1,1,0,-1,-1,0};
queue<ppap> qu;
void dfs(int x,int y,int zan){
	qu.push(mp(0,mp(x,y)));
	
	while(qu.size()){
		ppap r=qu.front();
		qu.pop();
		pa z=r.second;
		if(a[z.first][z.second]>0) continue;
		a[z.first][z.second]=1;
		ans++;
		if(r.first<zan)for(int i=0;i<6;i++)qu.push(mp(r.first+1,mp(z.first+ddx[i],z.second+ddy[i])));
	}
}

     signed main(){
string s;
     	cin>>s;
     	int l=s.length();
     	
     	s="+"+s;
     	l++;
     	
     	int ans1=0,r=0;
     	for(int i=1;i<l;i+=2){
     		if(s[i-1]=='+'){
     			ans1+=r;
     			r=s[i]-'0';
     		}
     		else{
     			r*=s[i]-'0';
     		}
     	}
     	ans1+=r;
     	int ans2=0;
     	for(int i=1;i<l;i+=2){
     		if(s[i-1]=='+')ans2+=s[i]-'0';
     		else ans2*=s[i]-'0';
     	}
int ri;
     	cin>>ri;
     	
     	if(ri==ans1 && ri==ans2){
     	cout<<"U"<<endl;
     	}
     	if(ri!=ans1 && ri==ans2){
     	cout<<"L"<<endl;
     	}
     	if(ri==ans1 && ri!=ans2){
     	cout<<"M"<<endl;
     	}
     	if(ri!=ans1 && ri!=ans2){
     	cout<<"I"<<endl;
     	}
     	
           	return 0;
           }
