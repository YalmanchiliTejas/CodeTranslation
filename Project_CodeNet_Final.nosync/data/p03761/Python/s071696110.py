from collections import defaultdict, Counter
N = int(input())
common_char = set()
d = defaultdict(int)

for i in range(N):
    counters = Counter(input())
    if i > 0:
        common_char = common_char & set(counters.keys())
    else:
        common_char = set(counters.keys())
    
    for c in common_char:
        if d[c] == 0:
            d[c] = counters[c]
        else:
            d[c] = min(d[c], counters[c])

ans = ""
for k in [chr(ord("a") + i) for i in range(26)]:
    if k in common_char:
        ans += k * d[k]
print(ans)