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
                           //     #define int long long
                                        #define inf  1000000007
                                        #define pa pair<int,int>
                                        #define ll long long
                                        #define pal pair<double,pa>
                                        #define ppa pair<int,int>
                                        #define ppap pair<pa,pa>
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-10)
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
                                    	bool operator == (const pas &p) const{
                                    		return x==p.x && y==p.y;
                                    	}
                                    };
int a[60];
           signed main(){
        
          int x,y,z;
           	cin>>x>>y>>z;
           	
           	x-=2*z+y;
           	cout<<1+x/(y+z)<<endl;
           	
           	return 0;
           	
           	
           }
             