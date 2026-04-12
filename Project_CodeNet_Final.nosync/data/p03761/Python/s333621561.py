import string
import collections

n = int(input())
S_count = []
for i in range(n):
    S_count.append(collections.Counter(input()))    

ans = ''    

for a in string.ascii_lowercase:
    c = 100
    for S_i in S_count:
        c = min(c, S_i[a])
    ans += a*c

print(ans)