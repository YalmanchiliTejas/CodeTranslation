n=int(input())
S=[input() for _ in range(n)]

import string

ans=''
for char in string.ascii_lowercase:
    cnt=50
    for s in S:
        cnt=min(cnt, s.count(char))
    ans+=char*cnt
print(ans)