from itertools import permutations

n, m = map(int, input().split())
ab = []
for i in range(m):
    ai, bi = map(int, input().split())
    ab.append([ai, bi])
ab = sorted(ab)

per_origin = []
for i in range(2, n+1):
    per_origin.append(i)

res = 0
for per in permutations(per_origin, len(per_origin)):
    root = [1] + list(per)
    flag = 0
    for i in range(n-1):
        if [root[i], root[i+1]] not in ab and [root[i+1], root[i]] not in ab:
            flag = 1
            break
    if not flag:
        res += 1

print(res)
