N = int(input())
A = list(map(int,input().split()))

proA = map(lambda x: x**2, A)

S = ((sum(A)**2-sum(proA))//2)

print(S%(10**9+7))