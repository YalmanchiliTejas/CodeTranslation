#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;

int main(){
	 int n,fsize,bsize,a;
	 stack<int> f;
	 queue<int> b;
	 
     cin >> n;
     if (n%2==0){
     	for (int i=0;i<n;i++){
     		cin >> a;
     		if (i%2==1){
     			f.push(a);
     		}
     		else{
     			b.push(a);
     		}
     	}
	}
	else{
		for (int i=0;i<n;i++){
			cin >> a;
			if (i%2==1){
     			b.push(a);
	     	}
    	 	else{
     			f.push(a);
     		}
     	}
	}
	
	fsize = f.size();
	bsize = b.size();
	
    for (int i=0;i<fsize;i++){
    	cout << f.top() << " ";
    	f.pop();
    }
     for (int i=0;i<bsize;i++){
    	cout << b.front() << " ";
    	b.pop();
    }

	return 0;
};