N=int(input())
from collections import Counter,defaultdict
s=input()
ddict=defaultdict(int)
for c in s:
  ddict[c]+=1
for i in range(N-1):
  s=input()
  cnt=Counter(s)
  for k in cnt.keys():
    ddict[k]=min(ddict[k],cnt[k])
  for k in ddict.keys():
    if not k in cnt.keys():
      ddict[k]=0
ans=""
for k in range(26):    
  c =chr(ord("a")+k)
  ans+=c*ddict[c]
print(ans)
  
