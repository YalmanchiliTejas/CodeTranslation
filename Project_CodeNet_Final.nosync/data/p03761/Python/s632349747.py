D=dict()
for i in "abcdefghijklmnopqrstuvwxyz":
  D[i]=100
n=int(input())
for _ in range(n):
  s=input()
  for j in D:
    D[j]=min(D[j],s.count(j))
ans=""
for k in "abcdefghijklmnopqrstuvwxyz":
  ans+=k*D[k]
print(ans)