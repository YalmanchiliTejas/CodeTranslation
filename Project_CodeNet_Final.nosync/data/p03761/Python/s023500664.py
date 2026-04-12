from collections import Counter

n = int(input())
s = [input() for _ in range(n)]

c = Counter(s[0])
for i in range(1,len(s)):
    c &= Counter(s[i])

ans=''
for letter, cnt in c.items():
    ans += letter*cnt

print(*sorted(ans), sep='')
