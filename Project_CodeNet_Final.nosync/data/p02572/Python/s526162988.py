n=int(input())
A = list(map(int,input().split()))
s=sum(A)
all=0
for i in A:
  s -= i
  all += (i*s)
ans=all%(10**9+7)
print(ans)