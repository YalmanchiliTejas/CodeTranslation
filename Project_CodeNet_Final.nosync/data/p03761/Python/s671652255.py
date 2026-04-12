n = int(input())
s = [input() for _ in range(n)]
az = "abcdefghijklmnopqrstuvwxyz"
counts = {}

for v in az:
    counts[v] = 10**9
    for i in range(n):
        counts[v] = min(counts[v], s[i].count(v))

ans = ""
for k, v in sorted(counts.items()):
    ans += k*v
print(ans)
