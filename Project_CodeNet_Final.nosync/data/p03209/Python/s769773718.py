N, X = map(int, input().split())
dim, ans = [0] * 51, [0] * 51
dim[0], ans[0] = 1, 1
for i in range(1, 51):
    dim[i] = 2 * dim[i - 1] + 3
    ans[i] = 2 ** (i + 1) - 1
def paty(n, x):
    if n == 0: return x
    elif x == 0: return 0
    else:
        if x == dim[n]: return ans[n]
        elif x == dim[n - 1] + 2: return ans[n - 1] + 1
        elif x <= dim[n - 1] + 1: return paty(n - 1, x - 1)
        else: return ans[n - 1] + 1 + paty(n - 1, x - (dim[n - 1] + 2))
print(paty(N, X))