from itertools import permutations

N, M = map(int, input().split())
AB = set([tuple(sorted(map(int, input().split()))) for _ in range(M)])

answer = 0
for pattern in permutations(range(2, N+1), N-1):
    pattern = [1] + list(pattern)
    for i in zip(pattern[:-1], pattern[1:]):
        if tuple(sorted(i)) not in AB:
            break
    else:
        answer += 1
print(answer)