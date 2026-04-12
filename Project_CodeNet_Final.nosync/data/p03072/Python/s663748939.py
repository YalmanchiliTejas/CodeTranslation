#!/usr/bin/python3
# -*- coding:utf-8 -*-

def main():
  n = int(input())
  Hs = list(map(int, input().split()))
  count = 1
  max= Hs[0]
  for i in range(1, n):
    if max <= Hs[i]:
      count += 1
      max = Hs[i]
  print(count)
  
if __name__=='__main__':
  main()

