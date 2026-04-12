import itertools
N, M = map(int, input().split())
D = {tuple(sorted(map(int, input().split()))) for x in range(M)}
cnt = 0
for i in itertools.permutations(range(2, N+1), N-1):
    l = [1]+list(i)
    cnt += sum(1 for x in zip(l,l[1:]) if tuple(sorted(x)) in D) == N-1
print(cnt)