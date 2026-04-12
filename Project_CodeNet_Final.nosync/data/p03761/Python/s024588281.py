from collections import Counter

n = int(input())
c = Counter(input())
for _ in range(n-1):
    nc = Counter(input())
    for k, v in c.items():
        c[k] = min(v, nc[k])
        
s = ''
for k, v in c.items():
    s += k*v
print(''.join(sorted(list(s))))