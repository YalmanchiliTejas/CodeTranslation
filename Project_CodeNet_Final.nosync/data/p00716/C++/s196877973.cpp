#include<iostream>
#define N 100
using namespace std;
int simple(int val,int year,double interest,int fee){
    //val gain gain_sum;
    int gain, gain_sum;
    for(int i=0;i<year;i++){
	gain=(int)val*interest;
	gain_sum+=gain;
	val-=fee;
    }
    return val+gain_sum;
}
int compound(int val, int year, double interest,int fee){
    int gain;
    for(int i=0;i<year;i++){
	gain=(int)val*interest;
	val+=gain;
	val-=fee;
    }
    return val;
}
    
int main(){
    int m;
    cin >>m;
    for(int i=0;i<m;i++){
	int M=0;
	int val,year,n;
	cin >> val>>year>>n;
	//how to manage asset
	for(int j=0;j<n;j++){
	    int type, fee;
	    double interest;
	    cin >> type >> interest >> fee;
	    if (type==0){
		int s=simple(val,year,interest,fee);
		if(s>M)M=s;
	    }
	    else{
		int c=compound(val,year,interest,fee);
		if (c>M)M=c;
	    }
	    
	}
	cout << M << endl;
    }
    
}