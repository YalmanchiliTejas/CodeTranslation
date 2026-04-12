from collections import defaultdict

n, m = map(int, input().split())
p = defaultdict(set)
for _ in range(m):
  ai, bi = map(int, input().split())
  p[ai].add(bi)
  p[bi].add(ai)

cnt = 0
cand_list = [(1, set(range(2, n + 1)))]

while(len(cand_list) != 0):
  c = cand_list.pop(0)

  if len(c[1]) == 0:
    cnt += 1
  for x in c[1] & p[c[0]]:
    remain = c[1].copy()
    remain.remove(x)
    cand_list.append((x, remain))

print(cnt)
