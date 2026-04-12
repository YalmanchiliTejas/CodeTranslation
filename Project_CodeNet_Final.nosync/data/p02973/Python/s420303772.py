import bisect;n,a,l=int(input()),[-int(input())],1
for i in range(n-1):
  b=-int(input())
  if a[-1]>b:a[bisect.bisect_right(a,b)]=b
  else:a.append(b);l+=1
print(l)