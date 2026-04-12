from bisect import bisect_right
def solve(n, a):
    ans = 1
    L = [-a[0]]
    for i in range(1, n):
        x = -a[i]
        if x >= L[-1]:
            ans += 1
            L.append(x)
        else:
            L[bisect_right(L, x)] = x
    return ans

n = int(input())
a = [int(input()) for i in range(n)]
print(solve(n, a))