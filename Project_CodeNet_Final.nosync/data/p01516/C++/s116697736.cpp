//05
#include<iostream>
#include<algorithm>
#include<complex>
#include<cmath>

using namespace std;

typedef complex<double> P;

double cr(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

double dt(P a,P b){
  return a.real()*b.real()+a.imag()*b.imag();
}

int main(){
  for(int n,m,l;cin>>n>>m>>l,n|m|l;){
    double d[100][100]={{}};
    int x[100],y[100],a[100],r[100];
    for(int i=0;i<n;i++){
      cin>>x[i]>>y[i]>>a[i]>>r[i];
      for(int j=0;j<i;j++){
	double ml=1<<30;
	for(int k=0;k<5;k++){
	  P aa=P(x[i],y[i])+polar(r[i]+.0,(a[i]+72*k+90)/180.*acos(0)*2);
	  P bb=P(x[i],y[i])+polar(r[i]+.0,(a[i]+72*k+144+90)/180.*acos(0)*2);
	  for(int l=0;l<5;l++){
	    P cc=P(x[j],y[j])+polar(r[j]+.0,(a[j]+72*l+90)/180.*acos(0)*2);
	    P dd=P(x[j],y[j])+polar(r[j]+.0,(a[j]+72*l+144+90)/180.*acos(0)*2);
	    if(cr(aa-bb,cc-bb)*cr(aa-bb,dd-bb)<0&&cr(cc-dd,aa-dd)*cr(cc-dd,bb-dd)<0){
	      ml=0;
	    }else{
	      P ls[2][2]={aa,bb,cc,dd};
	      for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
		  P a=ls[i][0];
		  P b=ls[i][1];
		  P c=ls[!i][j];
		  double dp;
		  if(dt(a-b,c-b)>0&&dt(b-a,c-a)>0){
		    dp=fabs(cr(a-b,c-b)/abs(a-b));
		  }else{
		    dp=min(abs(a-c),abs(b-c));
		  }
		  ml=min(ml,dp);
		}
	      }
	    }
	  }
	}
	d[i][j]=d[j][i]=ml;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	for(int k=0;k<n;k++){
	  d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	}
      }
    }
    cout.precision(6);
    cout<<fixed<<d[m-1][l-1]<<endl;
  }
  return 0;
}
	    