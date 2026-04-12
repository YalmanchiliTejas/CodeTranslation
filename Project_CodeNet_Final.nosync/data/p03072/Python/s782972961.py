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
  n = int(input())
  H = list(map(int,input().split()))
  cnt = 1
  for i in range(1,n):
    flag = True
    for j in range(0,i+1):
      if H[j] > H[i]:
        #print(i,j)
        flag = False
        break
    if flag:cnt+=1
  print(cnt)
if __name__ == '__main__':
  main()