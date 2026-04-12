mod = 10**9 + 7

N = int(input())
A = list(map(int, input().split()))

S1 = sum(A)**2
S2 = sum(a*a for a in A)

print((S1 - S2)//2 %mod)