from collections import Counter
n = int(input())
c = Counter(input())
for i in range(n-1):
    d = Counter(input())
    c = c & d
ans = ''.join([k * c[k] for k in sorted(c.keys())])
    
print(ans)