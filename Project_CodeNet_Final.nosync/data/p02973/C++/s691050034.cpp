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
pa operator-(const pa & l,const pa & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}  
                                
                int pr[200010];
                int inv[200010];
                
                int beki(int wa,int rr,int warukazu){
                	if(rr==0) return 1%warukazu;
                	if(rr==1) return wa%warukazu;
                	wa%=warukazu;
                	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
                	ll zx=beki(wa,rr/2,warukazu);
                	return (zx*zx)%warukazu;
                }
 
                
    			int comb(int nn,int rr){
    				if(rr<0 || rr>nn || nn<0) return 0;
    				int r=pr[nn]*inv[rr];
    				r%=mod;
    				r*=inv[nn-rr];
    				r%=mod;
    				return r;
    			}
                
                void gya(int ert){
                	pr[0]=1;
                	for(int i=1;i<=ert;i++){
                		pr[i]=(pr[i-1]*i)%mod;
                	}
                		inv[ert]=beki(pr[ert],mod-2,mod);
                	for(int i=ert-1;i>=0;i--){
                		inv[i]=inv[i+1]*(i+1)%mod;
                	}
                }
                
              //   cin.tie(0);
    		//	ios::sync_with_stdio(false);
    			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            
                 //sort(ve.begin(),ve.end(),greater<int>());
//    mt19937(clock_per_sec);
  //  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()) ;
      
       
       
                               //----------------kokomade tenpure------------
struct Segmax{
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
	
	vector<pa> vec;
	
	void shoki1(){
		
		vec.resize(2*cor+3, mp(0,0));
		for(int i=cor;i<2*cor;i++)vec[i].second=i-cor;
	}
		void shoki2(){
			for(int i=cor-1;i>0;i--) {
				if(vec[2*i].first>=vec[2*i+1].first) vec[i]=vec[2*i];
				else vec[i]=vec[2*i+1];
			}
		}
		
	void updadd(int x,int w){
		//x 項目に w加算
		x+=cor;
		vec[x].first+=w;
		while(1){
			x/=2;
			if(x==0) break;
			if(vec[2*x].first>=vec[2*x+1].first) vec[x]=vec[2*x];
			else vec[x]=vec[2*x+1];
		}
		
	}
	
	void updchan(int x,int w){
		//x項目をwに変更
		
		x+=cor;
		vec[x].first=w;
		
		while(1){
			x/=2;
			if(x==0) break;
			if(vec[2*x].first>=vec[2*x+1].first) vec[x]=vec[2*x];
			else vec[x]=vec[2*x+1];
		}
		
	}
	// [a,b)
	// k-th node
	// k no kukanha [l,r)
	pa segmax(int a,int b,int k=1,int l=0,int r=-10){
		if(r<0)r=cor;
		
	//	cout<<a<<" "<<b<<" "<<k<<" "<<l<<" "<<r<<endl;
		
		if(a<=l && r<=b){
			return vec[k];
		}
		if(r<=a || b<=l){
			return mp(-(1ll<<31),-1);
		}
		
		pa v1=segmax(a,b,k*2,l,(l+r)/2),v2=segmax(a,b,k*2+1,(l+r)/2,r);
		
		if(v1.first>=v2.first)return v1;
		else return v2;
	}

	
};
 signed main(){
 	
 
    	       cin.tie(0);
   		ios::sync_with_stdio(false);
	int n;
 	cin>>n;
 	vector<int> ve(n);
 	
 	for(int i=0;i<n;i++)cin>>ve[i];
 	
 	set<int>se;
 	map<int,int>ma;
 	for(auto v:ve)se.insert(v);
 	int cnt=1;
 	for(auto it=se.begin();it!=se.end();it++){
 		ma[*it]=cnt;
 		cnt++;
 	}
 	for(int i=0;i<n;i++)ve[i]=ma[ve[i]];
 	
 	Segmax ss;
 	ss.shoki1();
 	ss.shoki2();
 	
 	int ans=-1;
 	for(int i=0;i<n;i++){
 		int z=ss.segmax(ve[i],ss.cor).first;
 		
 		int nxt=max(ss.segmax(ve[i],ve[i+1]).first,z+1);
 	//	cout<<nxt<<endl;
 		ans=max(ans,nxt);
 		ss.updchan(ve[i],nxt);
 		
 		
 	}
 	cout<<ans<<endl;
 	

 	return 0;
 
  }
 