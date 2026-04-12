N = int(input())
A = list(map(int,input().split()))

MOD = 10**9+7

t = sum(A)**2
d = sum(a*a for a in A)
print(((t-d)//2)%MOD)