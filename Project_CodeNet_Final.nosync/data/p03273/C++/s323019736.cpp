#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int h, w ;
  cin >> h >> w ;
  vector<std::string> data ;
  for(int i = 0 ; i < h ; i++)
  {
    std::string str ;
    cin >> str ;
    for(int j = 0 ; j < w ; j++)
    {
      if(str.at(j) == '#')
      {
        data.push_back(str) ;
        break ;
      }
    }
  }

  vector<int> answer ;
  for(int i = 0 ; i < w ; i++)
  {
    for(int j = 0 ; j < data.size() ; j++)
    {
      if(data.at(j).at(i) == '#')
      {
        answer.push_back(i) ;
        break ;
      }
    }
  }

  for(int i = 0 ; i < data.size() ; i++)
  {
    for(int j = 0 ; j <= answer.size() ; j++)
    {
      if(j == answer.size())
      {
        cout << endl ;
        break ;
      }
      cout << data.at(i).at( answer.at(j) ) ;
    }
  }
}
