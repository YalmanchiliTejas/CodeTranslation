from collections import defaultdict

n = int(input())
S = []
d_list = []
strdict = {}

for i in range(n):
    s = input()
    S.append(s)
    if i == 0:
        for n in s:
            if n in strdict:
                strdict[n] += 1
            else:
                strdict[n] = 1
    else:
        d = defaultdict(int)
        for n in s:
            d[n] += 1
        for k in strdict:
            strdict[k] = min(strdict[k], d[k])

key = strdict.keys()
key = sorted(key)
ans = ''
for k in key:
    ans += k * strdict[k]
print(ans)