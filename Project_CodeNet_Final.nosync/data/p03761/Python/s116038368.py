from collections import Counter, defaultdict

N = int(input())
S = [0] * N

counts = []
for _ in range(N):
    counts.append(Counter(input()))

ans = ""
for c in "abcdefghijklmnopqrstuvwxyz":
    ans += c * min([x[c] for x in counts])

print(ans)
