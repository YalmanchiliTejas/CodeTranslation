from collections import Counter

n = int(input())
keys = set()
S = []
ans = {}
for i in range(n):
    counter = Counter(input())
    if i == 0:
        keys = set(counter.keys())
    else:
        keys = keys.intersection(counter.keys())
    tmp = {}
    for k in keys:
        tmp[k] = min(ans.get(k, 100), counter[k])
    ans = tmp
        
s = ''
for k in ans.keys():
    s += k * ans[k]
s = sorted(s)
sa = ''
for i in s:
    sa += i
print (sa)