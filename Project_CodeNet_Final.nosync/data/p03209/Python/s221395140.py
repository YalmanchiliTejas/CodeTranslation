import sys
input = sys.stdin.readline
n, x = [int(x) for x in input().strip().split()]
burgers = [False] * (n + 1)
burgers[0] = 'p'
leng = [1] * (n + 1)
patties = [1] * (n + 1)
for i in range(1, n+1):
    leng[i] = 2 * leng[i-1] + 3
    patties[i] = 2 * patties[i-1] + 1
def burger(l, x):
    if l == 0:
        ret = 1
    elif x == 1:
        ret = 0
    elif x <= leng[l] // 2:
        ret = burger(l-1, x-1)
    elif x == leng[l] // 2 + 1:
        ret = burger(l-1, x-2) + 1
    elif x < leng[l] - 2:
        ret = burger(l-1, leng[l-1]) + 1 + burger(l-1, x-2-leng[l-1])
    else:
        ret = patties[l]
    return ret

print(burger(n, x))