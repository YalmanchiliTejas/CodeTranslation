import itertools
n, m = map(int, input().split())
ab = set()

for _ in range(m):
    a, b = map(int, input().split())
    ab.add((a, b))
    ab.add((b, a))

cnt = 0
for x in itertools.permutations(range(1, n + 1)):
    if x[0] != 1:
        break
    flag = True
    for i in range(len(x)-1):
        if (x[i], x[i + 1]) not in ab:
            flag = False
            break
    if flag:
        cnt += 1
print(cnt)
