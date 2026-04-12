#include <bits/stdc++.h>

using namespace std;




int main()
{
  string V[100];

  int H,W;
  cin>>H>>W;

  int f[100];
  int g[100];

  vector<vector<int>> book;

  for(int i=0;i<H;i++){
	  cin>>V[i];
  }



  for(int i=0;i<H;i++){
	  bool flag =true;
	  for(int j=0;j<W;j++){
		  if(V[i][j]=='#'){
			  flag = false;
			  break;
		  }

	  }

	  f[i] = flag;



  }


  for(int j=0;j<W;j++){
	  bool flag = true;
	  for(int i=0;i<H;i++){
		  if(V[i][j]=='#'){
			  flag = false;
			  break;
		  }
	  }


	  g[j] = flag;
  }


  for(int i=0;i<H;i++){
	  if(f[i]){
		  continue;
	  }
	  for(int j=0;j<W;j++){
		  if(g[j]){
			  continue;
		  }

		  cout<<V[i][j];

	  }
	  cout<<endl;
  }






    return 0;
}


