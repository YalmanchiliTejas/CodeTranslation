from collections import deque
import sys, copy, itertools,bisect
input = sys.stdin.readline
  
n = int(input())
A = []
for i in range(n):
  a = int(input())
  A.append(a)
  
A.reverse() #逆順に変更

LDS =[A[0]] #初期値導入
#LDS=Longest Decreasing Subsequence
 
for i in range(1,n):
  x = A[i]
  index = bisect.bisect_right(LDS,x) #二分探索、right:同値は追加
  if index == len(LDS):
    LDS.append(x) #単純に後ろに追加する
  else:
    LDS[index]  = x
    #配列LDSの中で二分探索し、A[i]より大きい最小の位置を求め、その数字を置き換える  


#print(LDS)
print(len(LDS))    