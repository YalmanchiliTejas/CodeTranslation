from itertools import permutations

N, M = map(int, input().split())
ab = [[int(_) for _ in input().split()] for _ in range(M)]
Graph = [[] for _ in range(N+1)]
cand = list(permutations(range(1, N+1), N))
ans = 0

for i in ab:
    Graph[i[0]].append(i[1])
    Graph[i[1]].append(i[0])

for i in cand:
    if i[0] != 1:
        break
    flag = True
    for j in range(len(i)-1):
        if not (i[j+1] in Graph[i[j]]):
            flag = False
            break
    
    if flag:
        ans += 1

print(ans)