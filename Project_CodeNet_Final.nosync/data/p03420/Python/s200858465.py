#!/usr/bin/python3
# -*- coding:utf-8 -*-

def main():
  n, k = map(int, input().split())
  ans = 0
  for b in range(k+1, n+1):
    ans += (b-k) * (n//b) + max(n%b - (max(k-1, 0)), 0)
  print(ans)
  

if __name__=='__main__':
  main()

