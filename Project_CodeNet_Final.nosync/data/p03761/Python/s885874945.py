
from collections import Counter

N = int(input())

S = [input() for _ in range(N)]

c = Counter(S[0])

for i in range(1,N):
    c_tmp = Counter(S[i])
    for k in c.keys():
        if k in c and k in c_tmp:
            c[k] = min(c[k], c_tmp[k])
        else:
            c[k] = 0

ans = ""
for k in c:
    ans += k*c[k]

ans = list(ans)
ans.sort()
print("".join(ans))
