from collections import Counter

n = int(input())
s = [input() for i in range(n)]
c = []
for i in range(n):
    C = Counter(s[i])
    c.append(C)

ans = ""
for w in [chr(ord('a') + i) for i in range(26)]:
    num = 10 ** 2
    for i in range(n):
        num = min(num, c[i][w])
    ans += w * num
print(ans)