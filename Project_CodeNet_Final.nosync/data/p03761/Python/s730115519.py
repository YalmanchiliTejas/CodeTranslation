from collections import defaultdict
n = int(input())
s = input()
d = defaultdict(int)
for i in s:
    d[i] += 1

for i in range(1,n):
    s = input()
    di = defaultdict(int)
    for j in s:
        di[j] += 1
    for dik, div in di.items():
        d[dik] = min(d[dik],div)
    for dk,dv in d.items():
        d[dk] = min(dv,di[dk])

ans = []
for dk,dv in d.items():
    ans.append(dk*dv)

ans.sort()
print("".join(ans))
