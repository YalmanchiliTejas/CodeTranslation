#include<iostream>
using namespace std;

//int eval(int i, int j,int** diff,int* data);

int main()
{
  int n;
  cin>>n;
  long long int *data = new long long int[n];
  for(int i=0;i<n;i++)
  {
    cin>>data[i];
  }

  long long int **diff = new long long int*[n];
  for(int i=0;i<n;i++)
  {
    diff[i] = new long long int[n];
/*    for(int j=0;j<n;j++)
    {
      diff[i][j] = -1;
    }*/
  }
  for(int i=0;i<n;i++)
  {
    diff[i][i] = data[i];
  }
  for(int j=1;j<n;j++)
  {
    for(int i=0;i+j<n;i++)
    {
      diff[i][i+j] = max(data[i] - diff[i+1][i+j], data[i+j] - diff[i][i+j-1]);
    }
  }
  cout<<diff[0][n-1];
  //int ans = eval(0,n-1,diff,data);
  //cout<<ans;
  return 0;
}
/*
int eval(int i, int j,int** diff,int* data)
{
  if(diff[i][j] != -1)return diff[i][j];

  if(i==j){diff[i][j] = data[i]; return diff[i][j];}

  diff[i][j] = max(data[i]-eval(i+1,j,diff,data),data[j]-eval(i,j-1,diff,data));
  return diff[i][j];
}
*/
