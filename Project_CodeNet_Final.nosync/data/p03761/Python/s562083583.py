from collections import Counter
n = int(input())
S = Counter(input())

for i in range(n - 1):
    S &= Counter(input())

ans = ''
for k, v in S.items():
    ans += k * v
    
print(''.join(sorted(list(ans))))