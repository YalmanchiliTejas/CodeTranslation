from itertools import groupby as gb
n=int(input())
s=set(list("qazwsxedcrfvtgbyhnujmiklop"))
l=[500 for i in range(26)]
for i in  range(n):
  strd=sorted(input())
  vs=set(strd)
  sstr=sorted(list(vs))
  gr=[(a,len(list(b))) for a,b in gb(strd)]
  for t in s-vs:
    l[ord(t)-97]=0
  if sum(l)==0:print();exit()
  for v in vs:
    fg=ord(v)-97
    l[fg]=min(l[fg],gr[sstr.index(v)][1])
  s&=vs
ans=""
for i,c in enumerate(l):
  if c:
    f=chr(i+97)
    ans+=f*c
print(ans)