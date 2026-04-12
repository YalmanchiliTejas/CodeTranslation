import itertools

N,M = map(int,input().split())

con = [[] for _ in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    con[a].append(b)
    con[b].append(a)

per = list(itertools.permutations(range(N)))

count = 0

for x in per:
    if x[0] != 0:
        continue
    det = 0
    for k in range(N-1):
        if x[k+1] in con[x[k]]:
            continue
        else:
            det = -1
            break
    if det == 0:
        count += 1

print(count)


