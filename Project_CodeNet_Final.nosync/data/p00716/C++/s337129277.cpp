#include<iostream>

using namespace std;

int main() {
  int m;

  cin>>m;
  for(int i=0; i<m; i++) {
    int start, years, n;
    cin>>start>>years>>n;
    int maxProfit = 0;
    for(int j=0; j<n; j++) {
      int fukuri, charge;
      double nenri;
      cin>>fukuri>>nenri>>charge;
      //cout<<"limit: "<<fukuri<<" "<<nenri<<" "<<charge<<endl;

      int a=start, b;
      if(fukuri) {
	for(int k=0; k<years; k++) {
	  //cout<<a<<" ";
	  b = (int)(a*nenri); 
	  a = a+b-charge;
	  //cout<<b<<" "<<a<<endl;
	}
      }
      else {
	int totalCharge = 0;
	for(int k=0; k<years; k++) {
	  //cout<<a<<" ";
	  b = (int)(a*nenri);
	  a -= charge;
	  totalCharge += b;
	  //cout<<b<<" "<<a<<" "<<totalCharge<<endl;
	}
	a += totalCharge;
      }
      //cout<<"total: "<<a<<endl;
      if(a>maxProfit) {
	maxProfit = a;
      }
    }
    cout<<maxProfit<<endl;
  }
}