#quoted LIS from https://qiita.com/python_walker/items/d1e2be789f6e7a0851e5
import bisect

n=int(input())
arr=[int(input()) for _ in range(n)][::-1]
LIS=[arr[0]]
for i in range(1,n):
  if arr[i]>=LIS[-1]:
    LIS.append(arr[i])
  else:
    LIS[bisect.bisect_right(LIS,arr[i])]=arr[i]
print(len(LIS))