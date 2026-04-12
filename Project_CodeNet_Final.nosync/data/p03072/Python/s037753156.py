#!/usr/bin/env python3

# input = stdin.readline



def main():
  N = int(input())
  h = list(map(int,input().split()))
  highest = 0
  res = 0
  for i in range(N):
    if h[i] >= highest:
      res += 1
      highest = h[i]
  print(res)
  return

if __name__ == '__main__':
  main()
