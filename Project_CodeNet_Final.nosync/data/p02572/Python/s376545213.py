n = int(input())
A = list(map(int, input().split()))

mod = 10**9+7

x = (((sum(A))**2) // 2)
x -= (sum([a**2 for a in A]) // 2)
x %= mod
print(x)