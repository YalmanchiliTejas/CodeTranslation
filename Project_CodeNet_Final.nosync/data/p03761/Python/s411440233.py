n = int(input())
s = [input() for i in range(n)]

w = 'abcdefghijklmnopqrstuvwxyz'
ans = ''

for i in w:
    c = 100
    for j in range(n):
        c = min(c, s[j].count(i))
    ans += i*c

print(ans)