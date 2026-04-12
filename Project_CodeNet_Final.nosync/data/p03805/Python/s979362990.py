import itertools
N, M = map(int, input().split())
edges = {tuple(sorted(map(int, input().split()))) for _ in range(M)}
answer = 0
for pattern in itertools.permutations(range(2, N+1), N-1):
    l = [1] + list(pattern)
    answer += sum(1 for edge in zip(l, l[1:]) if tuple(sorted(edge)) in edges)==N-1
print(answer)    