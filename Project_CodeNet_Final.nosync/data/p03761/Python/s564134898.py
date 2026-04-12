from collections import defaultdict
n = int(input())
S = [input() for _ in range(n)]
dics = [defaultdict(int) for _ in range(n)]
keys = set()
for i in range(n):
    for c in S[i]:
        keys.add(c)
        dics[i][c] += 1
dic = defaultdict(int)
for k in dics[0]:
    dic[k] = dics[0][k]
for i in range(1, n):
    for k in keys:
        dic[k] = min(dic[k], dics[i][k])
ls = list(dic.keys())
ls.sort()
ans = ""
for k in ls:
    ans += k*dic[k]
print(ans)