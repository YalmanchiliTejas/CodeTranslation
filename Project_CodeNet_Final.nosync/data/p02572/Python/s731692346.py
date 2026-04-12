M = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))

print((((sum(A)**2) - sum(map(lambda x:x*x, A))) // 2) % M)
