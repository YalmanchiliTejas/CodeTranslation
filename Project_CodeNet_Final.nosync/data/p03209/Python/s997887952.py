n, x = map(int, input().split())

layers, patties = [1],[1]
for i in range(n):
    layers.append(layers[-1] * 2 + 3)
    patties.append(patties[-1] * 2 + 1)

def solve(cur, level):
    if level == 0:
        return 1 if cur > 0 else 0
    elif (layers[level] // 2) >= cur:
        return solve(cur - 1, level - 1)
    else:
        return solve(cur - layers[level-1] - 2, level - 1) + patties[level-1] + 1

print(solve(x,n))