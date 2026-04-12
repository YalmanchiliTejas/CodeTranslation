from collections import Counter
n = int(input())
s = input()
c = Counter(s)
for i in range(n-1):
    s = input()
    s = Counter(s)
    for i in s:
        if c[i]:
            c[i] = min(c[i],s[i])
    for i in c:
        if not s[i]:
            c[i] = 0
ans = ''
for i in c:
    ans += i*c[i]
print(''.join(sorted(ans)))