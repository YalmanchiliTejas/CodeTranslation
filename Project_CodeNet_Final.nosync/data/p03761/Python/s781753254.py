n = int(input())
s1 = input()
d = {}

for c in set(s1):
    d[c] = s1.count(c)

key_l = list(d.keys())
key_l.sort()

for _ in range(n-1):
    tmp = input()
    for c in key_l:
        d[c] = min(tmp.count(c), d[c])

ans = ''
for c in key_l:
    if d[c]:
        ans += c*d[c]
print(ans)