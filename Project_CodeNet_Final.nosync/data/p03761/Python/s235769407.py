n = int(input())
s = [input() for i in range(n)]
ans = ''

for i in range(97, 97 + 26):
    a = 50
    for j in range(n):
        a = min(a, s[j].count(chr(i)))
    ans += chr(i) * a

print(ans)
