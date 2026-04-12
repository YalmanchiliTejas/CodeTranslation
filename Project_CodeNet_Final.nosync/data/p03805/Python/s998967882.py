import itertools

N, M = map(int, input().split())
Lines = [set(map(int, input().split())) for _ in range(M)]

count = 0
for p in itertools.permutations(range(1, N+1)):
    if p[0] != 1:
        continue

    flag = True
    for i in range(N - 1):
        if not {p[i], p[i+1]} in Lines:
            flag = False
            break

    if flag:
        count += 1

print(count)