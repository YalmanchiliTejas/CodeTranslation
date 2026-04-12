al=[chr(ord('a') + i) for i in range(26)]
from collections import Counter

n=int(input())
S=[0]*n
d=[0]*n
for i in range(n):
  S[i]=input()
  d[i]=dict(Counter(S[i]))
  #print(d[i])
  
maxi=dict()
for str in d[0]:
  maxi[str] = d[0][str]
  for i in range(1,n):
    if str in d[i]:
      maxi[str]= min(maxi[str],d[i][str])
    else:
      maxi[str]=0
      break
#print(maxi)

ans=[]
for str in maxi:
  for i in range(maxi[str]):
    ans.append(str)
ans.sort()
print("".join(ans))