from collections import defaultdict
from string import ascii_letters

n = int(input())
words = [input() for _ in range(n)]

ans = ''
for c in ascii_letters:
    cnt = 50
    for w in words:
        cnt = min(cnt, w.count(c))
    ans += c * cnt
print(ans)