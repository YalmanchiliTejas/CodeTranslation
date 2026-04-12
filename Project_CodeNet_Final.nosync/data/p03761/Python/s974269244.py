from collections import Counter

n = int(input())
s = input()
c = Counter(s)
d = {}

for k, v in c.items():
    d[k] = v

key = set(c.keys())
for i in range(n-1):    
    s = input()
    c = Counter(s)
    key = key.intersection(set(c.keys()))
    for k in key:
        d[k] = min(d[k], c[k])

ans = ''
for k, v in sorted(d.items(), key=lambda x: x[0]):
	if k in key:
	    ans += k*v
    
print(ans)