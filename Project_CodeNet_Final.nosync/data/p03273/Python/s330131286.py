N, M = map(int, input().split())
a = [0] * N
for i in range(N):
    a[i] = list(input())

del_N = []
del_M = []

for i in range(N):
    if a[i].count('.') == M :
        del_N.append(i)

for i in range(M):
    tmp = []
    for j in range(N):
        tmp.append(a[j][i])
    if tmp.count('.') == N:
        del_M.append(i)



ans1 = []
for i in range(N):
    if i not in del_N:
        ans1.append(a[i])



ans2 = [[] for _ in range(len(ans1))]
for i in range(len(ans1)):
    for j in range(M):
        if j not in del_M:
            ans2[i].append(str(ans1[i][j]))



for i in range(len(ans2)):
    ans2[i] = ''.join(ans2[i])
    print(ans2[i])