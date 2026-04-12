#include <iostream>

using namespace std;

int main(){

  int m,n;
  int initial;
  int year;
  bool torf;
  double nenri;
  int tesuryo;

  int zandaka;
  int rishi;

  int max;

  cin >> m;
  
  for(int i=0;i<m;i++){// ???????????????????????°???????????????

    cin >> initial;
    cin >>year;
    cin >>n;

    max=0;
    
      for(int j=0;j<n;j++){ //?????¨????????°???????????????

	zandaka=initial;
	rishi=0;
	
	cin >> torf >> nenri >> tesuryo;
      
	if(!torf){
	  for(int k=0;k<year;k++){
	    rishi+=(int)(zandaka*nenri);
	    zandaka=zandaka-tesuryo;
	  }

	  if(max<zandaka+rishi)
	    max=zandaka+rishi;
	}

	else if(torf){
	  for(int l=0;l<year;l++){
	    rishi=(int)(zandaka*nenri);
	    zandaka=zandaka+rishi-tesuryo;
	  }

	  if(max<zandaka)
	    max=zandaka;

	}

      }
      cout << max << endl;
  }
  return 0;

}