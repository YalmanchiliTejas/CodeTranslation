# ABC058c
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
dicts = []
for _ in range(n):
    s = input()[:-1]
    d = dict()
    for i in s:
        if (d.get(i) != None):
            d[i] += 1
            continue
        d[i] = 1
    dicts.append(d)
# print(dicts)

ans = set(dicts[0])
for i in range(1, n):
    ans.intersection_update(dicts[i])
# print(ans)

ans2 = dict()
for i in dicts:
    for j in ans:
        if (ans2.get(j) != None):
            ans2[j] = min(i[j], ans2[j])
            continue
        ans2[j] = i[j]
# print(ans2)

st = []

for i in ans2.keys():
    for j in range(ans2[i]):
        st.append(i)
# print(st)

st.sort()
print(*st, sep='')