N, X = map(int, input().split())
thickness = [1]
patties = [1]
for _ in range(N):
    thickness.append(thickness[-1]*2 + 3)
    patties.append(patties[-1]*2 + 1)

def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x == 1:
        return 0
    elif x <= 1 + thickness[n-1]:
        return f(n-1, x-1)
    elif x == 2 + thickness[n-1]:
        return patties[n-1] + 1
    elif x <= 2 + 2*thickness[n-1]:
        return patties[n-1] + 1 + f(n-1, x-(2 + thickness[n-1]))
    else:
        return 2*patties[n-1] + 1
    
print(f(N, X))