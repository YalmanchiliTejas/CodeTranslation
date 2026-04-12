N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7
sumpre = 0
sumans = 0
for i in range(N-1):
    sumpre += A[i]
    sumans += A[i+1]*sumpre%mod
    sumans =sumans%mod
print(sumans)