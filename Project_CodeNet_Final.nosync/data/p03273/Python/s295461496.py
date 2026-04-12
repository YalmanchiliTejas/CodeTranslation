import numpy as np
lis = []
fragone = False
fraglast = False
row,num = list(map(int,input().split()))
for i in range(row):
  lis.append(list(input()))
arr = np.array(lis)
for nikai in range(2):
  arr = arr[np.any(arr == "#",axis=1), :]
  arr = arr.T
for item in arr:
  print("".join(item))