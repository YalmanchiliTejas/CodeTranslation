n=int(input())
s=[input() for i in range(n)]
a=[chr(ord('a')+j) for j in range(26)]
L=[]
for k in range(n):
  l=[0 for m in range(26)]
  for p in range(26):
    for q in range(len(s[k])):
      if s[k][q]==a[p]:l[p]+=1
  L.append(l)
b=[]
for r in range(26):
  c=[]
  for s in range(n):
    c.append(L[s][r])
  b.append(min(c))
ans=[]
for t in range(26):
  for u in range(b[t]):
    ans.append(a[t])
Ans=''.join(ans)
print(Ans)