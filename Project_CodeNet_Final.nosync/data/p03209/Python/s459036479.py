from functools import lru_cache

@lru_cache()
def eat(n, x):  # x = number of levels, return = number of patties
    #print(n,x)
    if n == 0:
        if x == 1:
            return 1  # 1 = patty
    if x == 1:
        return 0  # 0 = bun
    elif x <= 1 + thickness[n - 1]:
        return eat(n - 1, x - 1)
    elif x <= 1 + thickness[n - 1] + 1:
        return patties[n - 1] + 1
    elif x <= 1 + thickness[n - 1] + 1 + thickness[n-1]:
        return patties[n - 1] + 1 + eat(n - 1, x - 1 - thickness[n-1] - 1)
    else:
        return patties[n - 1] + 1 + patties[n - 1]

    return 0

N,X = map(int, input().split())

thickness = [0] * (N+1)
thickness[0] = 1
for i in range(1,N+1):
    thickness[i] = 1 + thickness[i-1] + 1 + thickness[i-1] + 1
patties = [0] * (N+1)
patties[0] = 1
for i in range(1,N+1):
    patties[i] = patties[i-1] + 1 + patties[i-1]

print(eat(N,X))
