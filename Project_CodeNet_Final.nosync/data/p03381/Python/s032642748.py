from copy import copy
N = int(input())
X = list(map(int,input().split()))
sortX = copy(X)
sortX.sort(reverse = True)
median1 = sortX[N // 2 - 1]
median2 = sortX[N // 2]
for i in X:
  if i >= median1: print(median2)
  else: print(median1)  