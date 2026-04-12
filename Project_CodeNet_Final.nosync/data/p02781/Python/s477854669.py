from itertools import combinations
N = list(map(int, input()))
K = int(input())

nlen = len(N)
ans = 0
if K <= nlen:
    cmb = [9] * nlen
    for n in N:
        if n != 0:
            cmb[0] = n - 1
            for x in combinations(cmb, K):
                y = x[0]
                for z in x[1:]:
                    y *= z
                ans += y
            if K == 1:
                ans += 1
                break
            K -= 1
        cmb.pop()
print(ans)