import itertools
N, M = map(int, input().split())
E = set([tuple(sorted(map(int, input().split()))) for x in range(M)])
cnt = 0
for i in itertools.permutations(range(2,N+1), N-1):
    l = [1]+list(i)
    if sum(1 for x in range(N-1) if tuple(sorted(l[x:x+2])) in E) == N-1:
        cnt += 1
print(cnt)