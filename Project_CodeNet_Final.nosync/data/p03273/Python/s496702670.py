#
# Written by NoKnowledgeGG @YlePhan
# ('ω')
#
#import math
#mod = 10**9+7
#import itertools
#import fractions
#import numpy as np
#mod = 10**4 + 7
"""def kiri(n,m):
  r_ = n / m
  if (r_ - (n // m)) > 0:
    return (n//m) + 1
  else:
    return (n//m)"""
 
def main():
  h,w = map(int,input().split())
  rec = [list(input()) for _ in range(h)]
  #print(rec)
  flag = False
  # yoko
  for i in range(h):
    for j in range(w):
      if rec[i][j] == '.':
        flag = True
        pass
      else:
        flag = False
        break
    if flag:
      for r in range(w):
        rec[i][r] = 'd'
  #print(rec)
  
  
  # tate
  for j in range(w):
    for i in range(h):
      if rec[i][j] == '.' or rec[i][j] == 'd':
        flag = True
        pass
      else:
        flag = False
        break
    if flag:
      for r in range(h):
        rec[r][j] = 'd'
        
  #print(rec)
  
  
  for i in range(h):
    new = ""
    for j in range(w):
      if rec[i][j] != 'd':
        new += rec[i][j]
    if len(new) != 0:print(new)
if __name__ == '__main__':
  main()