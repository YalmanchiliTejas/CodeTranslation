n = int(input())
s = [input() for _ in range(n)]

inf = 10 ** 18
count = [inf] * 26
for t in s:
    c = [0] * 26
    for x in t:
        i = ord(x) - ord('a')
        c[i] += 1
    for i in range(26):
        count[i] = min(count[i], c[i])

ans = ''
for i in range(26):
    ans += chr(i + ord('a')) * count[i]
print(ans)