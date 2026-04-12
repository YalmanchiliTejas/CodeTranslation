n=int(input())
a=list(map(int,input().split()))
b=sorted(a)
v1=b[n//2-1]
v2=b[n//2]
for i in range(n):
  if a[i]<=v1:
    print(v2)
  else:
    print(v1)