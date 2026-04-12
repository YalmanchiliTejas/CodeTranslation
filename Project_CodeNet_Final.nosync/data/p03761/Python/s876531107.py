from collections import Counter
N = int(input())
src = [input() for i in range(N)]

ctr = Counter(src[0])
for s in src[1:]:
    ctr &= Counter(s)

ans = ''
for k,v in sorted(ctr.items()):
    ans += k*v
print(ans)