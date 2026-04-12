from sys import stdin
input = stdin.readline


def main():
  X = int(input())

  if X >= 30:
    print('Yes')
  else:
    print('No')


if(__name__ == '__main__'):
  main()
