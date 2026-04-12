#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int h, w;
  char *data;
  char tmp[100];
  int idx = 0;
  bool hmark[100];
  bool wmark[100];

  cin >> h >> w;

  // init
  for (int i = 0; i < h; i++)
  {
    hmark[i] = false;
  }
  for (int i = 0; i < w; i++)
  {
    wmark[i] = false;
  }

  // read data
  data = new char[h * w];
  for (int i = 0; i < h; i++)
  {
    cin >> tmp;
    for (int j = 0; j < w; j++)
    {
      data[idx++] = tmp[j];
    }
  }

  // calc
  for (int i = 0; i < h; i++)
  {
    bool blackAvailable = false;
    for (int j = 0; j < w; j++)
    {
      if (data[i * w + j] == '#')
      {
        blackAvailable = true;
        break;
      }
    }
    hmark[i] = !blackAvailable;
  }

  for (int i = 0; i < w; i++)
  {
    bool blackAvailable = false;
    for (int j = 0; j < h; j++)
    {
      if (data[j * w + i] == '#')
      {
        blackAvailable = true;
        break;
      }
    }
    wmark[i] = !blackAvailable;
  }

  // write
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (hmark[i] == false && wmark[j] == false)
      {
        cout << data[i * w + j];
      }
    }
    if (hmark[i] == false)
    {
      cout << endl;
    }
  }

  delete data;
}
