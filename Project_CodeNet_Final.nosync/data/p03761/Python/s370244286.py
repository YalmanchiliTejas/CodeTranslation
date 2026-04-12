n = int(input())
s = [input() for _ in range(n)]
l = [0]*26
for i,w in enumerate('abcdefghijklmnopqrstuvwxyz'):
    k = [0]*n
    for j in range(n):
        k[j] += s[j].count(w)
    l[i] += min(k)
ans = ''
for i,w in enumerate('abcdefghijklmnopqrstuvwxyz'):
    ans += w*l[i]
print(ans)