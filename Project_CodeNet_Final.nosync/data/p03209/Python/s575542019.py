n, x = map(int, input().split())

patties, layers = [1], [1]
for i in range(n):
    patties += [patties[-1] * 2 + 1]
    layers += [layers[-1] * 2 + 3]

def solve(N, cur):
    if N == 0:
        return 1 if cur > 0 else 0
        
    return solve(N-1, cur-1) if cur <= (layers[N] // 2) else solve(N-1, (cur-layers[N-1])-2) + patties[N-1] + 1

print(solve(n,x))