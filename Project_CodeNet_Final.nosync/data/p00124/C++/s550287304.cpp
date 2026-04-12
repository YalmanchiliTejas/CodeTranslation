#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Team
{
  public:
    Team(string& name, int win, int draw, int index);

    bool operator<(const Team& other) const;
    void Show();

  private:
    string m_name;
    int m_score;
    int m_index;
};

Team::Team(string& name, int win, int draw, int index) :
  m_name(name), m_index(index)
{
  m_score = win * 3 + draw * 1;
}

bool Team::operator<(const Team& other) const
{
  return m_score == other.m_score ? m_index > other.m_index : m_score < other.m_score;
}

void Team::Show()
{
  cout << m_name << "," << m_score << endl;
}

int main(void)
{
  bool flag = false;
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;
    if (flag) cout << endl;
    flag = true;
    
    vector<Team> teams;
    for (int i = 0; i < n; ++i)
    {
      string name;
      int win, lose, draw;
      cin >> name >> win >> lose >> draw;
      Team buf_team(name, win, draw, i);
      teams.push_back(buf_team);
    }
    sort(teams.rbegin(), teams.rend());
    for (auto team : teams)
    {
      team.Show();
    }
  }
  return 0;
}