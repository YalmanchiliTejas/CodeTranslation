from collections import defaultdict
n = int(input())
d = defaultdict(int)
S = [input() for _ in range(n)]
for i in range(ord('a'), ord('z')+1):
  c = chr(i)
  count = S[0].count(c)
  for s in S[1:]:
    count = min(count, s.count(c))
  d[c] = count

for k,v in sorted(d.items()):
  for _ in range(v):
    print(k, end='')
print()