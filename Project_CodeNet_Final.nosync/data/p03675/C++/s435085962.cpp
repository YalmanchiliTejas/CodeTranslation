#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,i,j,dir,n;
struct type{
	type *n1,*n0;
	int x;
}*end1,*end0;
int main(){
	cin>>n;
	cin>>a;
    dir=1;
    end1=new(type);
    end0=end1;
    end1->x=a;
    for(i=2;i<=n;i++){
    	dir=!dir;
    	cin>>a;
    	if(dir){
    		end1->n1=new(type);
    		end1->n1->n0=end1;
    		end1->n1->x=a;
    		end1=end1->n1;
    	}else{
    		end0->n0=new(type);
    		end0->n0->n1=end0;
    		end0->n0->x=a;
    		end0=end0->n0;
    	}
    }
    type *k;
    if(dir){
    	k=end1;
    	while(k!=end0){
    		cout<<k->x<<' ';
    		k=k->n0;
    	}
    	cout<<k->x<<endl;
    }else{
    	k=end0;
    	while(k!=end1){
    		cout<<k->x<<' ';
    		k=k->n1;
    	}
    	cout<<k->x<<endl;
    }
}
