import itertools

N, M = map(int, input().split())
ab = [0] * M
for i in range(M):
  ab[i] = list(map(int, input().split()))

perms = itertools.permutations(range(1, N+1))
ans = 0
for perm in perms:
  if perm[0] != 1:
    continue
  is_goal = True
  for i in range(N-1):
    a = perm[i]
    b = perm[i+1]
    if not a < b:
      a, b = b, a
    if not [a, b] in ab:
      is_goal = False
  if is_goal:
    ans += 1

print(ans)
