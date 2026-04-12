n = int(input())
s = [list(input()) for _ in range(n)]

ans = dict()

a = ord('a')
for x in range(a, a + 26):
    c = chr(x)
    ans[c] = s[0].count(c)

for i in range(1, n):
    for c in ans.keys():
        ans[c] = min(ans[c], s[i].count(c))

res = ""
for x in range(a, a + 26):
    c = chr(x)
    res = res + c * ans[c]

print(res)
