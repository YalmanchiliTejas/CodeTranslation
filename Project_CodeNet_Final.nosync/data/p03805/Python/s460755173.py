N, M = map(int, input().split())
p = [list(map(int, input().split())) for i in range(M)]
import itertools
v = list(map(list, itertools.permutations(range(2,N+1), N-1)))
cnt = 0
for i in range(len(v)):
    vit = True
    v_i = [1]+v[i]
    for j in range(N-1):
        if sorted(v_i[j:j+2]) not in p:
            vit = False
    if vit:
        cnt += 1
print(cnt)