from collections import Counter
n = int(input())
can_use = Counter(input())
for _ in range(n-1):
    S = Counter(input())
    for k in "abcdefghijklmnopqrstuvwxyz":
        can_use[k] = min(can_use[k], S[k])
ans = []
for k, v in can_use.items():
    for _ in range(v):
        ans.append(k)
ans.sort()
print("".join(ans))
