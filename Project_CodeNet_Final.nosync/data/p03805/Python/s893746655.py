# ABC_054_C_One_Stroke_Path.py

from itertools import permutations
N, M = list(map(int, input().split()))
L=[]
for _ in range(M):
    L.append(list(map(int, input().split())))
# print(L)

P = list(permutations(range(1,N+1)))
# print(P)
ct = 0
for i in P:
    if i[0]==1 and \
    all((sorted([i[j], i[j+1]]) in L) for j in range(N-1)):
        ct += 1
print(ct)