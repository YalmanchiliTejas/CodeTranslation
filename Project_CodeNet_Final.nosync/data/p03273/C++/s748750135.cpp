#include<bits/stdc++.h>
using namespace std;
char ccnt[10010][10010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
 /*   double t,x;
    cin>>t>>x;
    t=t/x;
    cout<<t*1.0<<'\n';*/
  
   /* int a,b,c;
    cin>>a>>b>>c;
    cout<<(a*b)/2<<'\n';*/

   /* int d;
    cin>>d;
    if(d==22){
        cout<<"Christmas Eve Eve Eve"<<'\n';
    }else if(d==23){
        cout<<"Christmas Eve Eve"<<'\n';
    }else if(d==24){
        cout<<"Christmas Eve"<<'\n';
    }else if(d==25){
        cout<<"Christmas"<<'\n';
    }*/

   /* int x,y;
    cin>>x>>y;
    y=y/2;
    cout<<x+y<<'\n';*/

   /* int n,a,b;
    cin>>n;
    if(n==1){
        cout<<"Hello World"<<'\n';
    }else{
        cin>>a>>b;
        cout<<a+b<<'\n';
    }*/

   /* int n;
    cin>>n;
    if(n==111){
        cout<<999<<'\n';
    }else if(n==119){
        cout<<991<<'\n';
    }else if(n==199){
        cout<<911<<'\n';
    }else if(n==191){
        cout<<919<<'\n';
    }else if(n==999){
        cout<<111<<'\n';
    }else if(n==911){
        cout<<199<<'\n';
    }else if(n==919){
        cout<<191<<'\n';
    }else if(n==991){
        cout<<119<<'\n';
    }*/

  /*  int a[5];
    for(int i=0; i<3; i++){
        cin>>a[i];
    }
    sort(a,a+3,greater<int>());
    a[0]=a[0]*10;
    a[0]=a[0]+a[1]+a[2];
    cout<<a[0]<<'\n';*/

  /*  int a,b;
    cin>>a>>b;
    a=a*b;
    if(a%2==0){
        cout<<"No"<<'\n';
    }else{
        cout<<"Yes"<<'\n';
    }*/

  /*int a,b;
    cin>>a;
    b=a/2;
    if(a%2==0){
        cout<<b*b<<'\n';
    }else{
        cout<<b*(b+1)<<'\n';
    }*/

  /*  int n,i;
    cin>>n>>i;
    cout<<n-i+1<<'\n';*/

    int h,w;
    cin>>h>>w;  
	vector<string> a(h);
	for (int i=0; i<h; i++) {
		    cin>>a[i];
	}   
 
	vector<bool> cnt(h,false); 
	vector<bool> ent(w,false);
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			if(a[i][j]=='#') {
				    cnt[i] = true;
			    	ent[j] = true;
			    }   
		    }
	    }
	for(int i=0; i<h; i++) {
		if(cnt[i]){   
			for(int j=0; j<w; j++) {
				if(ent[j]) {
					cout<<a[i][j];
				    }
			    }
		    	cout<<'\n';
	    	}
	}
}   