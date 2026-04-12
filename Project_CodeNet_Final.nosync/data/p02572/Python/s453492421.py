n = int(input())
A = list(map(int, input().split()))

S = sum(A)**2 - sum(map(lambda x:x**2, A))

print(S//2 % 1000000007)

