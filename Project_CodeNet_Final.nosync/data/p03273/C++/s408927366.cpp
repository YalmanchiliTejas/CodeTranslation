#include <bits/stdc++.h>

using namespace std;


int main (void) 
{

  /* Variable_Proclamation */
  int H, W;    // input

  int i, j;    // subscript
  bool line_flag;


  /* Input, Array_Proclamation */
  cin >> H >> W;
  vector< vector<char> > a(H, vector<char>(W)); //input
  vector<bool> adr_i(H, false); 
  vector<bool> adr_j(W, false); 
  
  for(i=0; i<H; i++)
  {
    for(j=0; j<W; j++)
    {
      cin >> a.at(i).at(j);
    }
  }


  /* Calculation */
  for(i=0; i<H; i++)
  {
    for(j=0; j<W; j++)
    {
      
      if(a.at(i).at(j) == '#')
      {
        adr_i.at(i) = true;
        adr_j.at(j) = true;
      }

    }
  }


  /* Output */
  cout << endl;

  for(i=0; i<H; i++)
  {
  
    line_flag = false;
    for(j=0; j<W; j++)
    {
      if(adr_i.at(i) == true && adr_j.at(j) == true)
      {
        cout << a.at(i).at(j);
        line_flag = true;
      }
    }

    if(line_flag == true)
    {
      cout << endl;
    }

  }


  return 0;

}
