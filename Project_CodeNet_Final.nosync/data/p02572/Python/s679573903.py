MOD = 10**9 + 7
def solve(n, a):
    t = sum(a)
    return sum((t-x)*x for x in a) // 2 % MOD

n = int(input())
a = list(map(int, input().split()))
print(solve(n, a))
