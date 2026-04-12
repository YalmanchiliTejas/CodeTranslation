import string

n = int(input())
s = []
for _ in range(n):
    s.append(input())

az = string.ascii_lowercase
counts = {}
 
for v in az:

    counts[v] = float("inf")
    for i in range(n):
        counts[v] = min(counts[v], s[i].count(v))
 

ans = ""
for k, v in sorted(counts.items()):
    ans += k*v
print(ans)