n=int(input())
a=list(map(int,input().split()))
cnt=0
while max(a)>=n:
  s=0
  for i in range(n):
    s+=a[i]//n
  for i in range(n):
    a[i]+=(s-a[i]//n)-(a[i]//n)*n
  cnt+=s
print(cnt)