from collections import Counter
n = int(input())

S = Counter(list(input()))

for _ in range(n-1):
    S = S & Counter(list(input()))

ans = ""
for k,v in sorted(S.items()):
    ans += k*v
print(ans)