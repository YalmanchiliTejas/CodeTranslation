from collections import Counter
n = int(input())
C = [Counter(input()) for _ in range(n)]
dic = {}
for key in C[0]:
    dic[key] = C[0][key]
for c in C[1:]:
    dl = []
    for key in dic:
        if key in c:
            dic[key] = min(dic[key], c[key])
        else:
            dl.append(key)
    for key in dl:
        del dic[key]
dic = sorted(dic.items(), key = lambda x: x[0])
ans = ''
for x in dic:
    ans += x[0] * x[1]
print(ans)