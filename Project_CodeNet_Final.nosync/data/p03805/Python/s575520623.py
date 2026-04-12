import itertools
N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(M)]
#print(ab)
N_list = [i for i in range(1, N + 1)]

Np_list = list(itertools.permutations(N_list))
ans = 0
for p in Np_list:
    #print(p)
    flag = True
    if p[0] != 1:
        continue
    for j in range(len(p) - 1):
        if p[j] < p[j+1] and [p[j], p[j + 1]] not in ab:
            flag = False
        elif p[j] > p[j + 1] and ([p[j + 1], p[j]] not in ab):
            flag = False
    if flag:
        ans += 1
print(ans)