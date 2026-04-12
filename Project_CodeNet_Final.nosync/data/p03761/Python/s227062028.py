#058_C
from collections import Counter
n=int(input())
s=Counter(input())
for _ in range(n-1):
    t=Counter(input())
    s&=t
ans=''
for key,value in sorted(s.items()):
    ans+=key*value
print(ans)