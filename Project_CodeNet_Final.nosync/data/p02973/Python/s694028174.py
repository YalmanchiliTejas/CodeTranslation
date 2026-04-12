import bisect
n = int(input())
a = [- int(input()) for i in range(n)]
tmp = [a[0]]
for i in range(1,n):
  idx=bisect.bisect_right(tmp,a[i])
  if idx==len(tmp):
    tmp.append(a[i])
  else:
    tmp[idx] =a[i]
print(len(tmp))