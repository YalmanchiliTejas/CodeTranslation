n = int(input())
ns = list(list(input()) for i in range(n))
ns_set = set()
for i in range(n):
    ns_set |= set(ns[i])
from collections import defaultdict
dic = defaultdict(lambda : 50)
for i in range(n):
    for s in ns_set:
        if s in ns[i]:
            dic[s] = min(dic[s], ns[i].count(s))
        else:
            dic[s] = 0
result = ''
for key, value in sorted(dic.items(), key=lambda x: x[0]):
    result += key*value
print(result)