N = int(input())
A = [int(a) for a in input().split()]

mod = 10**9 + 7

print(((sum(A)**2 - sum([i**2 for i in A]))//2) % mod)