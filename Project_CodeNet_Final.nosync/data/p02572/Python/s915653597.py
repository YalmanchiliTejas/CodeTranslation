N = int(input())
A = list(map(int,input().split()))
a = 0
b = 0
mod = 10**9 + 7
for i in range(N):
    a += A[i]
    b += A[i]**2
    a = a 
    b = b 
a = a ** 2 
ans = (a - b) // 2 % mod
if ans < 0:
    ans += mod
print(ans)