from collections import Counter
n = int(input())
S = [input() for _ in range(n)]
s_counters = [Counter(s) for s in S]
base = s_counters[0]
for i in range(1, n):
    base = base & s_counters[i]
ans = []
for k, v in base.items():
    ans += (k * v)
print("".join(sorted(ans)))