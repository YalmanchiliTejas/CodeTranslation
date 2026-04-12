import bisect
n=int(input())
a=[int(input()) for _ in range(n)][::-1]
lis=[a[0]]
for i in a[1:]:
  if i>=lis[-1]:
    lis.append(i)
  else:
    lis[bisect.bisect_right(lis,i)]=i
print(len(lis))