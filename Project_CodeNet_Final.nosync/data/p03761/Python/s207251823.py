n = int(input())
a = list(input() for _ in range(n))

ad = []
for i in range(n):
    ad.append(dict())
    for c in a[i]:
        ad[i][c] = ad[i].get(c, 0) + 1#d[i]はS[i]の(各文字:文字数)の辞書
chrs = 'abcdefghijklmnopqrstuvwxyz'
d = dict()
for c in chrs:
    buf = float('inf')
    for i in range(n):
        buf = min(buf, ad[i].get(c, 0))
    d[c] = buf
d = list(tuple((k, v)) for k, v in d.items())
d = sorted(d, key=lambda x:x[0])
ans = ''
for k, v in d:
    ans += k * v
print(ans)       