import itertools
N, M = [int(x) for x in input().split()]
lst = [[int(x) for x in input().split()] for i in range(M)]
N_lst = list(range(1, N + 1))
per = []

def check(tup):
    for i in range(N - 1):
        x = tup[i]
        y = tup[i + 1]
        if x > y:
            x, y = y, x
        if not [x, y] in lst:
            return False
    return True

for v in itertools.permutations(N_lst):
    if v[0] == 1:
        per.append(v)
cnt = 0
for p in per:
    if check(p): cnt += 1
print(cnt)
