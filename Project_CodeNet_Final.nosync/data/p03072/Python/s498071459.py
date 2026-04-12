n=int(input())
l=list(map(int,input().split()))
s=1
for i in range(1,n):
  if l[i]>=max(l[0:i]):
    s=s+1
print(s)