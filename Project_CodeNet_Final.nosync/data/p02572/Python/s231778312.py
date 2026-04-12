n = int(input())
A = list(map(int, input().split()))
M = 10**9 + 7

S = sum(A)
S2 = sum(map(lambda x: x**2, A))
print(((S**2 - S2)// 2)%M)

