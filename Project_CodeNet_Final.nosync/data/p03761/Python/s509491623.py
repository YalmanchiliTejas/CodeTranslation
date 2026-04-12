from collections import defaultdict,Counter
n = int(input())
s = list(input())
c = Counter(s)


for i in range(1,n):
    s = list(input())
    d = defaultdict(int)
    for ss in s:
        d[ss] += 1
    for cc in c.keys():
        if c[cc] > d[cc]:
            c[cc] = d[cc]

ans = []
for cc in c.keys():
    for i in range(c[cc]):
        ans.append(cc)
ans.sort()
print(''.join(ans))