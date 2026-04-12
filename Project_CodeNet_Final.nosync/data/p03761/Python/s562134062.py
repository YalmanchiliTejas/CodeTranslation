n=int(input())
s=[]
from collections import Counter
for i in [0]*n:
    s.append(Counter(input()))
ans=""
for i in "abcdefghijklmnopqrstuvwxyz":
    tmp=[]
    for j in s:
        tmp.append(j[i])
    ans+=i*min(tmp)
print(ans)