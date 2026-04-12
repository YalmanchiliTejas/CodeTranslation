#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
  Stack();
  ~Stack();
  void push(char color);
  char pop();

private:
  char* m_stack;
  int m_size;
};

Stack::Stack()
{
  m_stack = new char[1000];
  m_size = 0;
}

Stack::~Stack()
{
  delete[] m_stack;
}

void Stack::push(char color)
{
  m_stack[m_size] = color;
  m_size++;
}

char Stack::pop()
{
  m_size--;
  return m_stack[m_size];
}


int main()
{
  string command;
  char color;
  int n;
  cin >> n;
  Stack* stacks = new Stack[n];
  while ( cin >> command )
  {
    if ( command == "push" )
    {
      int i;
      cin >> i >> color;
      i--;
      stacks[i].push(color);
    }
    else if ( command == "pop" )
    {
      int i;
      cin >> i;
      i--;
      cout << stacks[i].pop() << endl;
    }
    else if ( command == "move" )
    {
      int i,j;
      cin >> i >> j;
      i--;j--;
      color = stacks[i].pop();
      stacks[j].push(color);
    }
    else if ( command == "quit" )
    {
      break;
    }
  }
  delete[] stacks;
  return 0;
}