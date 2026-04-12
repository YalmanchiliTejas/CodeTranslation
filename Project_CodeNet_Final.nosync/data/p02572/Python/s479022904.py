N = int(input())
A = list(map(int, input().split()))

mod = 10**9+7

S = sum(A)
S2 = sum(map(lambda x:x*x, A))

print((S*S - S2)//2 % mod)