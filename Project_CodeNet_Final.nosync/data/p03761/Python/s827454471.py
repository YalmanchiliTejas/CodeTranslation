from collections import Counter as co
n=int(input())
s=set(list("qazwsxedcrfvtgbyhnujmiklop"))
l=[500 for i in range(26)]
for i in  range(n):
  gr=sorted([a for a in co(input()).items()])
  vs=set([a for a in zip(*gr)][0])
  for t in s-vs:
    l[ord(t)-97]=0
  if sum(l)==0:print();exit()
  for v, coun in gr:
    fg=ord(v)-97
    l[fg]=min(l[fg],coun)
  s&=vs
ans=""
for i,c in enumerate(l):
  if c:
    f=chr(i+97)
    ans+=f*c
print(ans)