from collections import Counter
n = int(input())
s = input()
c = Counter(s)
for i in range(n-1):
    s = input()
    c &= Counter(s)
ans = ''
for i in sorted(c):
    ans += i*c[i]
print(ans)