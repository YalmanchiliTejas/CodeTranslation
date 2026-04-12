N = int(input())
A = list(map(int, input().split()))
sumA = sum(A)
s = sum(a*a for a in A)
ans = sumA*sumA - s
print((ans//2)%(10**9+7))
