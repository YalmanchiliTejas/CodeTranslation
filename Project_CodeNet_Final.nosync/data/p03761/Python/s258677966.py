n=int(input())
li=[input() for i in range(n)]
from collections import Counter 
cnt=[None]*n 
ans=''
for i in range(n):
    cnt[i]=Counter(li[i])
for i in range(97,123):
    ch=chr(i)
    mini=10**9
    for j in range(n):
        mini=min(mini,cnt[j][ch])
    ans+=ch*mini 
print(ans)