import bisect
n=int(input())
x=[int(input())for _ in range(n)]
a=[-x[0]]
l=1
for i in range(1,n):
  b=-x[i]
  if a[-1]>b:
    if a[0]>b:a[0]=b;continue
    a[bisect.bisect_right(a,b)]=b
  else:a.append(b);l+=1
print(l)