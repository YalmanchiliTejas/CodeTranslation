from collections import Counter
n = int(input())
d = {}
for i in range(n):
    if i == 0:
        d = Counter(input())
    else:
        tmp = Counter(input())
        tmp2 = {}
        for k,v in d.items():
            if k in tmp:
                tmp2[k] = min(d[k],tmp[k])
        d = tmp2

ans = ""
for k,v in d.items():
    ans += v*k

print(''.join(map(str, sorted(ans))))
