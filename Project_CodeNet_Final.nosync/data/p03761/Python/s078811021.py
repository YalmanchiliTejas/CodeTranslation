n = int(input())
s = [[i for i in input()] for _ in range(n)]
dic = {}
for si in s[0]:
    if si not in dic.keys():
        dic[si] = [0 for _ in range(n)]
    dic[si][0] += 1
for i in range(1, n):
    for si in s[i]:
        if si not in dic.keys(): continue
        else:
            dic[si][i] += 1
dic = sorted(dic.items(), key=lambda x:x[0])
ans = ""
for k, v in dic:
    mi = min(v)
    if mi == 0: continue
    else:
        ans += k*mi
print(ans)