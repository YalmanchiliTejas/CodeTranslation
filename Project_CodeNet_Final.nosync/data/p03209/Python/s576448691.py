from functools import lru_cache

N,X = map(int,input().split())

bargar = [1 for i in range(N+1)]
for i in range(1, N+1):
    bargar[i] = bargar[i-1]*2 +3

patie = [1 for i in range(N+1)]
for i in range(1, N+1):
    patie[i] = patie[i-1]*2 +1

# @lru_cache(maxsize=1000)
def rec(dim):
    global X
    if dim==0:
        X -= 1
        if X >= 0: return 1
        else: return 0

    res = 0; X -= 1
    if X==0: return res

    if X>=bargar[dim-1]: res += patie[dim-1]; X-= bargar[dim-1]
    else: res += rec(dim-1)
    if X==0: return res

    res += 1; X -= 1
    if X==0: return res

    if X>=bargar[dim-1]: res += patie[dim-1]; X-= bargar[dim-1]
    else: res += rec(dim-1)
    if X==0: return res

    X -= 1
    if X==0: return res
    return res

print(rec(N))
# print(bargar)
# print(patie)
