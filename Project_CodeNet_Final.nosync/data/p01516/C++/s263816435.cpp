#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))


struct makehtml{
	vector<string> ss;
	
	makehtml(){}
	/*
	ctx.beginPath()
	ctx.moveTo(50.000000,100.000000);
	ctx.lineTo(150.000000,100.000000);
	ctx.stroke();
	
	ctx.fillStyle = "rgb(0,0,0)";
	
	ctx.beginPath();
	ctx.arc(168,59,3,0,360);
	ctx.fill();

	*/
	
	void out(const char* name,double mag){
		char fname[100];
		sprintf(fname,"%s.html",name);
		FILE* fp = fopen(fname,"w");
		if(fp==NULL){
			eprintf("can't open %s\b",fname);
			exit(-1);
		}
		fprintf(fp,"<html>\n<head>\n<title>");
		fprintf(fp,"%s",name);
		fprintf(fp,"</title>\n</head>\n<body>\n");
		fprintf(fp,"<p>name: %s</p>",name);
		fprintf(fp,"<canvas id=\"vis\" width=\"%d\" height=\"%d\"></canvas>",2000,2000);
		fprintf(fp,"<script>\n");
		fprintf(fp,"var vis = document.getElementById('vis');\nvar ctx = vis.getContext('2d');\n");
		
		rep(i,ss.size()){
			fprintf(fp,"%s\n",ss[i].c_str());
		}
		
		fprintf(fp,"</script>\n");
		fprintf(fp,"</body>\n</html>\n");
		fclose(fp);
	}

} makehtml_instance;

void addhtml(string s){
	makehtml_instance.ss.push_back(s);
}

void outhtml(string s,double mag){
	makehtml_instance.out(s.c_str(),mag);
}

void randcolhtml(){
	char ns[100];
	sprintf(ns,"ctx.fillStyle = \"rgb(%d,%d,%d)\";",rand()%128,rand()%128,rand()%128);
	addhtml(ns);
	sprintf(ns,"ctx.strokeStyle = \"rgb(%d,%d,%d)\";",rand()%128,rand()%128,rand()%128);
	addhtml(ns);
}

void inithtml(){
	makehtml_instance.ss.clear();
}


struct pos{
	double x,y;
	double norm,norm2;
	pos tov(pos a){
		return (a-(*this));
	}
	pos operator+(pos a)const{
		pos res=a;
		res.x+=x; res.y+=y;
		res=pos(res.x,res.y);
		return res;
	}
	pos operator-(pos a)const{
		pos res=(*this);
		res.x-=a.x; res.y-=a.y;
		res=pos(res.x,res.y);
		return res;
	}
	pos scalar(double a){
		pos res=(*this);
		res.x*=a; res.y*=a;
		res=pos(res.x,res.y);
		return res;
	}
	double dot(pos a){
		return x*a.x + y*a.y;
	}
	double cross(pos a){
		return x*a.y - y*a.x;
	}
	double theta(pos a){
		double nt=dot(a)/(norm*a.norm);
		nt=acos(max(-1.0,min(1.0,nt)));
		double ns=(cross(a)/(norm*a.norm));
		if(ns<0)nt*=-1;
		return nt;
	}
	pos(double ix,double iy){
		x=ix; y=iy;
		norm2=x*x+y*y;
		norm=sqrt(norm2);
	}
	pos(){}
	string str(){
		char ns[50];
		sprintf(ns,"(%lf %lf)",x,y);
		return	string(ns);
	}
	void outh(double mag){
		char ns[50];
		addhtml("ctx.beginPath();"); 
		sprintf(ns,"ctx.arc(%lf,%lf,%lf,0,360);",x*mag,y*mag,5.0); addhtml(ns);
		addhtml("ctx.fill();");
	}
	static pos polar(double r,double t){
		return pos(r*cos(t),r*sin(t));
	}
	bool  operator<(pos a) const{
		//if(x!=a.x)return (x<a.x);
		//return (y<a.y);
		if(y!=a.y)return (y<a.y);
		return (x<a.x);
	}	
	bool operator>(pos a)const{ return (a<(*this)); }	
};
struct line{
	pos p,q;
	pos vec;
	string str(){
		return ("("+p.str()+"-"+q.str()+")");
	}
	void outh(double mag){
		char ns[50];
		addhtml("ctx.beginPath();");
		sprintf(ns,"ctx.moveTo(%lf,%lf);",p.x*mag,p.y*mag); addhtml(ns);
		sprintf(ns,"ctx.lineTo(%lf,%lf);",q.x*mag,q.y*mag); addhtml(ns);
		addhtml("ctx.stroke();");
	}
	bool iscross(line a){
		double da,db;
		da=vec.cross( p.tov(a.p) );
		db=vec.cross( p.tov(a.q) );
		if(da*db>=0)return false;
		da=a.vec.cross( a.p.tov(p) );
		db=a.vec.cross( a.p.tov(q) );
		return (da*db<0);
	}
	line(pos ip,pos iq){
		p=ip; q=iq;
		vec=p.tov(q);
	}
	line(){}
	double dist(pos a){
		if(p.tov(a).dot( p.tov(q) )<0)return p.tov(a).norm;
		if(q.tov(a).dot( q.tov(p) )<0)return q.tov(a).norm;
		return abs(vec.cross(p.tov(a))/vec.norm);
	}
	double dist(line a){
		if(iscross(a))return 0;
		return min( min(dist(a.p),dist(a.q)) , min(a.dist(this->p),a.dist(this->q)));
	}
	pos crosspos(line a){
		/*
		double d1=a.vec.cross(a.p.tov(p))/a.vec.norm;
		double d2=a.vec.cross(a.p.tov(q))/a.vec.norm;
		bool isc=(d1*d2<0);
		d1=abs(d1); d2=abs(d2);
		double sc;
		if(!isc){
			if(d1>d2)sc = d1/(d1-d2);
			else sc=d1/(d2-d1);
		}
		else sc = d1/(d1+d2);
		return (p+vec.scalar(sc));*/
		
		double t = a.vec.cross(a.p-p)/a.vec.cross(vec);
		return (p+vec.scalar(t));
	}
	line bisection(){//?????´????????????
		//???????¨??????????90????????£???????????????
		pos fr=(p+q).scalar(0.5);
		pos to=fr+pos(-vec.y,vec.x);
		return line(fr,to);
	}
};
double lowofcos_getcos(double a,double b,double c){
	return ((a*a+b*b-c*c)/(2*a*b));
}
struct circle{
	pos p;
	double r;
	line koten(circle a){
		pos cv=p.tov(a.p);
		double br=atan2(cv.y,cv.x);
		double dr=acos(lowofcos_getcos( r, cv.norm, a.r));
		pos p1= p+pos::polar(r,br+dr);
		pos p2= p+pos::polar(r,br-dr);
		if(p1>p2)swap(p1,p2);
		return line(p1,p2);
	}
	circle(pos ip,double ir){
		p=ip; r=ir;
	}
	circle(){}
	void outh(double mag){
		char ns[50];
		addhtml("ctx.beginPath();"); 
		sprintf(ns,"ctx.arc(%lf,%lf,%lf,0,360);",p.x*mag,p.y*mag,r*mag); addhtml(ns);
		//addhtml("ctx.fill();");
	}
};

struct polygon{
	vector<pos> ps;
	polygon(){}
	void outh(double mag){
		char ns[50];
		addhtml("ctx.beginPath();");
		int ls=ps.size();
		sprintf(ns,"ctx.moveTo(%lf,%lf);",ps[ls-1].x*mag,ps[ls-1].y*mag); addhtml(ns);
		rep(i,ps.size()){
			sprintf(ns,"ctx.lineTo(%lf,%lf);",ps[i].x*mag,ps[i].y*mag); addhtml(ns);
		}
		addhtml("ctx.stroke();");
	}
	double area(){
		double res=0;
		rep(i,ps.size()){
			pos no=ps[i],to=ps[(i+1)%ps.size()];
			res+=(no.x+to.x)*(no.y-to.y);
		}
		if(res<0)reverse(ps.begin(),ps.end());
		return abs(res)/2;
	}
	polygon(pos a,pos b){
		ps.push_back(a);
		ps.push_back(pos(a.x,b.y));
		ps.push_back(b);
		ps.push_back(pos(b.x,a.y));
	}
	line gete(int a){
		a%=ps.size();
		return line(ps[a],ps[(a+1)%ps.size()]);
	}
	int isin(pos a){//?????´??????2,?????£????????????1,?????????0
		double as=0;
		rep(i,ps.size()){
			line ne=gete(i);
			if(ne.dist(a)<=0)return 1;
			pos v1=a.tov(ne.p);
			pos v2=a.tov(ne.q);
			as+=v1.theta(v2);
		}
		if(abs(as)<1e-6)return 0;
		return 2;
	}
	polygon convex_full(){
		polygon res;
		int ns=ps.size();
		vector<pos> vs(2*ns);
		sort(ps.begin(),ps.end());
		int k=0;
		rep(i,ns){
			pos np=ps[i];
			while(k>1 && vs[k-2].tov(vs[k-1]).cross(vs[k-1].tov(np))<-1e-6)k--;
			vs[k]=np; k++;
		}
		int t=k;
		ireg(i,0,ns-2){
			pos np=ps[i];
			while(k>t && vs[k-2].tov(vs[k-1]).cross(vs[k-1].tov(np))<-1e-6)k--;
			vs[k]=np; k++;
		}
		vs.resize(k-1);
		swap(vs,res.ps);
		return res;
	}
	polygon cut(line a){//???????????????????????????
		polygon res;
		rep(i,ps.size()){
			line ne=gete(i);
			double d1=a.vec.cross(a.p.tov(ne.p));
			double d2=a.vec.cross(a.p.tov(ne.q));
			if(d1<1e-6)res.ps.push_back(ne.p); //?????£????????£???eps
			if(d1*d2<-1e-6)res.ps.push_back(a.crosspos(ne)); //?????£????????????eps
		}
		return res;
	}
	
	vector<polygon> voronoi(vector<pos> ps){
		vector<polygon> res;
		rep(i,ps.size()){
			polygon np(*this);
			rep(j,ps.size()){
				if(i==j)continue;
				line nl = line(ps[j],ps[i]).bisection();
				
				np = np.cut(nl);
			}
			res.push_back(np);
		}
		return res;		
	}
	polygon mult(polygon a){
		return a;
	}
};


int n,st,gl;
vector<vector<line> > ss;

const double pi = 3.14159265358979;

double ds[105][105];

int main(void){
	for(;;){
		ss.clear();
		scanf("%d%d%d",&n,&st,&gl); st--; gl--;
		if(n==0)break;
		
		//inithtml();
		rep(k,n){
			double x,y,a,r;
			scanf("%lf%lf%lf%lf",&x,&y,&a,&r); a = (a/360.0) * 2 * pi;
			double nn = (144.0/360.0) * 2 * pi;
			pos bs(x,y);
			vector<line> ns;
			rep(i,5){
				pos fr(-r*sin(a+(i*nn)),r*cos(a+(i*nn)));
				pos to(-r*sin(a+((i+1)*nn)),r*cos(a+((i+1)*nn)));
				line ne(fr+bs,to+bs);
				ns.push_back(ne);
				//ne.outh(30);
			}
			ss.push_back(ns);
		}
		
		//outhtml("o",30);
		
		rep(i,n)ds[i][i]=0;
		rep(i,n)rep(j,i){
			double nd = 1e10;
			rep(p,5)rep(q,5){
				nd = min(nd,ss[i][p].dist(ss[j][q]));
			}
			ds[i][j]=ds[j][i]=nd;
		}
		
		rep(k,n)rep(i,n)rep(j,n){
			ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
		}
		printf("%.8f\n",ds[st][gl]);
	}	
				
	return 0;
}