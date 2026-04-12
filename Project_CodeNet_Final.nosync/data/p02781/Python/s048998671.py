#!/usr/bin/python3
# -*- coding:utf-8 -*-

from math import factorial

def main():
  s = list(map(int, input().strip()))
  k = int(input())
  dp = []
  dp.append([[0]*(len(s)+1) for _ in range(k+1)])
  dp.append([[0]*(len(s)+1) for _ in range(k+1)])
  dp[0][0][0] = 1
  
  for i, c in enumerate(s):
    for j in range(k+1):
        for d in range(10):
          nj = j
          if d != 0:
            nj+=1
          if nj > k:
            continue
            
          if d < c:
            dp[1][nj][i+1] += dp[0][j][i]
          if d == c:
            dp[0][nj][i+1] += dp[0][j][i]
          dp[1][nj][i+1] += dp[1][j][i]
            
  print(dp[0][k][len(s)]+dp[1][k][len(s)])

if __name__=='__main__':
  main()



