from collections import Counter
n = int(input())
s = [input() for _ in range(n)]
cnt = Counter(s[0])

for w in s[1:]:
    cnt &= Counter(w)

ans = ''
for k, v in sorted(cnt.items()):
    ans += k * v
print(ans)