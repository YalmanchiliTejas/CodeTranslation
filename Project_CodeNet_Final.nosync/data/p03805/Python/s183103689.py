N,M = map(int,(input().split()))
line = [[] for _ in range(N)]
for i in range(M):
    a,b = map(int,(input().split()))
    line[a-1].append(b-1)
    line[b-1].append(a-1)

# N!通りの順列
# lはタプルなのでlist()でリスト化して使うべし
import itertools
t = [i for i in range(N)]
l = list(itertools.permutations(t))
# 以下でリスト化
for i in range(len(l)):
    l[i] = list(l[i])

ans = 0
for i in range(len(l)):
    for j in range(N-1):
        if not l[i][j+1] in line[l[i][j]]:
            break
    else:
        if l[i][0] == 0:
            ans += 1

print(ans)