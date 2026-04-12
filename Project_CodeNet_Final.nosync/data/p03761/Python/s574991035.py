from collections import Counter
n = int(input())
s = [input() for _ in range(n)]

cnt = Counter(s[0])
for i in s[1:]:
    cnt &= Counter(i)
ans = ""
for i, v in sorted(cnt.items()):
    ans += i * v
print(ans)