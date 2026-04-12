from collections import Counter
from collections import defaultdict
N = int(input())
S = [Counter(input()) for _ in range(N)]
c = defaultdict(lambda: 999999999)
for s in S:
    for ch in "abcdefghijklmnopqrstuvwxyz":
        if ch in s:
            c[ch] = min(c[ch], s[ch])
        else:
            c[ch] = 0
ans = ""
for ch in "abcdefghijklmnopqrstuvwxyz":
    ans = "".join([ans, ch * c[ch]])
print(ans)