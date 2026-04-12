from collections import Counter
n = int(input())
s = Counter(input())

for i in range(n - 1):
    s = s & Counter(input())
    
ans = ''
for k, v in s.items():
    ans += k * v

print(''.join(sorted(list(ans))))