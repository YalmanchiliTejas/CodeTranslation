from itertools import permutations

N,M = list(map(int, input().split()))
S = set([])
for _ in range(M):
    A,B = list(map(int, input().split()))
    S.add((A,B))
    S.add((B,A))
count = 0
node = [i for i in range(1,N+1)]
lis = list(permutations(node))

for v in lis:
    flag = 0
    if v[0] != 1:
        continue
    for i in range(N-1):
        if (v[i],v[i+1]) in S:
            continue
        else:
            flag += 1
    if flag == 0:
            count += 1

print(count)