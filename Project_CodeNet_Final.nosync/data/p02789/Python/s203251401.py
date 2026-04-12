def solve():
    N, M = map(int, input().split())
    return 'Yes' if N == min(N, M) else 'No'

print(solve())