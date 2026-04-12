#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h,w;
  	cin>>h>>w;
  	vector<string> grids;
  	string str;
  	for(int i=0 ; i<h ; ++i)
    {
    	cin>>str;
      	if(str.find("#")!=string::npos)
        grids.push_back(str);
    }
  	map<int,bool> white_cols;
  	for(int i=0 ; i<grids[0].length() ; ++i)
    {
      	bool white_col=true;
    	for(int j=0 ; j<grids.size() ; ++j)
        {
        	if(grids[j][i]=='#')
            {
            	white_col=false;
              	break;
            }
        }
		white_cols[i]=white_col;
    }
  	for(int i=0 ; i<grids.size() ; ++i)
    {
    	for(int j=0 ; j<grids[i].length() ; ++j)
        {
        	if(white_cols[j])
        	continue;
          	cout<<grids[i][j];
        }
      	cout<<endl;
    }
	return 0;
}