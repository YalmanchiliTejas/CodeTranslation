mod = 10**9 + 7
N = int(input())
A = [int(x) for x in input().split()]

s = sum(A)
S = s**2
D = sum([a**2 for a in A])

print(int((S - D) // 2) % mod)
