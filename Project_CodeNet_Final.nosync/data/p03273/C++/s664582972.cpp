#include <bits/stdc++.h>

using namespace std;


int main (void) 
{

  /* Variable_Proclamation */
  int H, W;    // input

  int i, j;    // subscript
  int k;
  int i_cnt, j_cnt; 


  /* Input, Array_Proclamation */
  cin >> H >> W;
  vector< vector<char> > a(H, vector<char>(W)); //input
  
  for(i=0; i<H; i++)
  {
    for(j=0; j<W; j++)
    {
      cin >> a.at(i).at(j);
    }
  }


  /* Initialize */
  i_cnt = 0;
  j_cnt = 0;


  /* Calculation */

  //j_cnt
  for(i=0; i<H; i++)
  {

    for(j=0; j<W; j++)
    {

      if(a.at(i).at(j) == '.')
      {
        j_cnt++;
      }

      if(j_cnt == W)
      {

        // swap( a.at(i), a.at(H-1) );
        // a.pop_back();
        a.erase(a.begin() +i);
        H--;

        // swap( a.at(i), a.at(H-1) );
        // for(k=0; k<H-1; k++)
        // {
        //   swap( a.at(k), a.at(k+1) );
        // }
        i--;



      }

    }

    j_cnt = 0;

  }

  // /* Output */
  // cout << endl; // delete

  // for(i=0; i<H; i++)
  // {

  //   for(j=0; j<W; j++)
  //   {
  //     cout << a.at(i).at(j);
  //   }

  //   cout << endl;

  // }


  // return 0;


  // Transposition
  vector< vector<char> > trans_a(W, vector<char>(H));
  
  for(i=0; i<H; i++)
  {
    for(j=0; j<W; j++)
    {
      trans_a.at(j).at(i) = a.at(i).at(j);
    }
  }



  //i_cnt
  for(j=0; j<W; j++)
  {

    for(i=0; i<H; i++)
    {

      if(trans_a.at(j).at(i) == '.')
      {
        i_cnt++;
      }

      if(i_cnt == H)
      {

        // swap( trans_a.at(j), trans_a.at(W-1) );
        // trans_a.pop_back();
        trans_a.erase(trans_a.begin() +j);
        W--;

        // for(k=0; k<W-1; k++)
        // {
        //   swap( trans_a.at(k), trans_a.at(k+1) );
        // }
        j--;

        // cout << "aaa\n";
      }
      // else
      // {
      //   cout << "bbb\n";
      // }

    }

    i_cnt = 0;

  }


  // Re:Transposition

  vector< vector<char> > ans_a(H, vector<char>(W)); //output

  for(j=0; j<W; j++)
  {
    for(i=0; i<H; i++)
    {
      ans_a.at(i).at(j) = trans_a.at(j).at(i);
    }
  }


  /* Output */
  cout << endl; // delete

  for(i=0; i<H; i++)
  {

    for(j=0; j<W; j++)
    {
      cout << ans_a.at(i).at(j);
    }

    cout << endl;

  }


  return 0;


}
