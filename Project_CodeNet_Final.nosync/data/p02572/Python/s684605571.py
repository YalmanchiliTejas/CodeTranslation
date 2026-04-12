N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7
S = sum(A)**2
SS = 0

for i in range(N):
    SS += A[i]**2

print(((S - SS)//2)%mod)


    