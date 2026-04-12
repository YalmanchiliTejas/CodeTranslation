from collections import defaultdict
from collections import Counter
n = int(input())

li = []
for _ in range(n):
    li.append(list(map(str, input().rstrip())))

lineup = set(li[0])

for i in li[1:]:
    lineup = lineup & set(i)

d = defaultdict(int)

for i in lineup:
    d[i] = 51

for i in d.keys():
    for j in li:
        if d[i] > j.count(i):
            d[i] = j.count(i)

ans = []
for k, v in d.items():
    ans.append(k * v)

ans.sort()

print("".join(ans))