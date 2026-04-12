import itertools

N, M = map(int, input().split())
V = [[] for _ in range(N)]
bag = set()
for _ in range(M):
    a, b = map(int, input().split())
    bag.add(a)
    bag.add(b)
    V[a-1].append(b)
    V[b-1].append(a)

count = 0
for c in itertools.permutations(bag):
    if not c[0] == 1:
        continue
    flag = False
    for i in range(N-1):
        if not c[i+1] in V[c[i]-1]:
            flag = True
            break
    if not flag:
        count += 1
print(count)
