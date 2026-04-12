n=int(input())
S=[list(input()) for _ in range(n)]

chars=[chr(ord('a')+i) for i in range(26)]
ans=[]
for c in chars:
  min_=float('inf')
  for i in range(n):
    min_ = min(min_,S[i].count(c))
  for _ in range(min_):
    ans.append(c)
print(*ans,sep='')