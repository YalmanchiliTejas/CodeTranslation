import collections
n=int(input())
s=str(input())
s=list(s)
ans=collections.Counter(s)
for i in range(1,n):
  s=str(input())
  s=list(s)
  c=collections.Counter(s)
  ans=ans&c
ans="".join(sorted(ans.elements()))
print(ans)