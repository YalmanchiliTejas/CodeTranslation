N = int(input())
A = [int(i) for i in input().split()]
ans = sum(A)**2 - sum(list(map(lambda x : x**2, A)))
print((ans // 2) % (10**9 + 7))