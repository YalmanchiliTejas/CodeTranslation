from collections import deque
import sys, copy, itertools,bisect
input = sys.stdin.readline

def isOK(LIST, index, key):  #key以上で最大のindexを返す
  if LIST[index] <= key:
    return True
  else:
    return False

def meguru_binary_search(LIST, key):
  ng = -1
  ok = len(LIST)
  while abs(ok-ng) > 1:
    mid = (ok + ng) //2 #"//"は切り捨て除算
    if isOK(LIST, mid, key):
      ok = mid
    else:
      ng = mid
  return ok  
  

n = int(input())
A = []
for i in range(n):
  a = int(input())
  A.append(a)
  
#A.reverse()
#print(A)

LDS =[A[-1]] #初期値導入
#LDS=Longest Decreasing Subsequence
 
for i in range(2,n+1):
  x = A[-i]
  index = bisect.bisect_right(LDS,x)
  if index == len(LDS):
    LDS.append(x) #単純に後ろに追加する
  else:
    LDS[index]  = x
    #配列LDSの中で二分探索し、A[i]より小さい最小の位置を求め、その数字を置き換える  

#print(LDS)
print(len(LDS))    