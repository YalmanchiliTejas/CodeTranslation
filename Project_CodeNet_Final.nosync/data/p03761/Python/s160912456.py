ans=""
n=int(input())
s=[input() for _ in range(n)]
from collections import Counter
d=Counter(s[0])
for i in s[1:]:
    d&=Counter(i)
for i ,k in sorted(d.items()):
    ans+=i*k
print(ans)