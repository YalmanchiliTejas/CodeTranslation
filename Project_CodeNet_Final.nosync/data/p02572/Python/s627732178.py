N = int(input())
A = tuple(map(int,input().split()))
mod = 10**9+7
B = [0]*N
for i in range(N):
    B[i] = A[i]**2
s1, s2 = 0, 0 
for i in range(N):
    s1 += A[i]
    s2 += B[i]
s1 = s1**2
ans = (s1 -s2)//2%mod
print(ans)