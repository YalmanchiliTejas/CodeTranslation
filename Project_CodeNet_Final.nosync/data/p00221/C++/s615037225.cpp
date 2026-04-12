#include<iostream>
#include<string>
#include<list>
using namespace std;

int N, M;
list<int> players;

bool check(int n, string s)
{
  if(n % 5 == 0 && n % 3 == 0)
    return s == "FizzBuzz";
  if(n % 5 == 0)
    return s == "Buzz";
  if(n % 3 == 0)
    return s =="Fizz";
  return s == to_string(n);
}

int main()
{
loop:
  cin >> M >> N;
  if(!N)
    return 0;

  players.clear();
  for(int i = 0; i < M; i++)
    players.push_back(i + 1);
  auto p = players.begin();
  for(int i = 1; i <=N; i++)
  {
    string s;
    cin >> s;
    if(players.front() == players.back())
      continue;
    if(!check(i, s))
      p = players.erase(p);
    else 
      ++p; 
    if(p == players.end())
      p = players.begin();
  }
  for(auto v : players)
  {
    cout << v;
    if(v != players.back())
      cout << " ";
  }
  cout << endl;
  goto loop;
}