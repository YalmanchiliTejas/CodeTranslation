from bisect import bisect_right
n=int(input())
a=[int(input()) for _ in range(n)]
a=a[::-1]
lis=[a[0]]
for i in range(1,n):
  if lis[-1]<=a[i]:
    lis.append(a[i])
  else:
    inde=bisect_right(lis,a[i])
    lis[inde]=a[i]
print(len(lis))
  