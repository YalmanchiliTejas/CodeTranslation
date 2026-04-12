n = int(input())
A = list(map(int,input().split()))
mod = (10**9) + 7
t = 0
sum = 0
for i in range(1,n):
    sum += A[i]
for i in range(n-1):
    t += (A[i]*sum)%mod
    sum -=  A[i+1]
t = t%mod
print(t)