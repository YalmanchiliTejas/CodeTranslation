n = int(input())
s = [input() for _ in range(n)]

d = [float("inf")]*26
for i in range(n):
    e = [0]*26
    for si in s[i]:
        e[ord(si) - 97] += 1
    for i in range(26):
        d[i] = min(d[i], e[i])

ans = ""
for i in range(26):
    ans += chr(i + 97) * d[i]

print(ans)