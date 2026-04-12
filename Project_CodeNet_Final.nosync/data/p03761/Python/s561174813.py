from collections import defaultdict

d = defaultdict(lambda:0)
n = int(input())

for a in input():
    d[a] += 1

for i in range(n-1):
    dd = defaultdict(lambda:0)
    for j in input():
        dd[j] += 1
    dc = defaultdict(lambda:0)
    for k, j in d.items():
        if(k in dd):
            dc[k] = min(j, dd[k])
    d = dc

ans = ""
for i, j in sorted(d.items(), key=lambda x:x[0]):
    ans += i*j
print(ans)