import collections
n=int(input())
S=[input() for i in range(n)]
C=[]
CT=[]
ans=""
ABC="abcdefghijklmnopqrstuvwxyz"
for s in S:
  C.append(collections.Counter(s))
for x in ABC:
  count=C[0][x]
  for i in range(1,n):
    count=min(count,C[i][x])
  CT.append(count)
for i in range(26):
  ans+=ABC[i]*CT[i]
print(ans)