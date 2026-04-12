N = int(input())
A = list(map(int, input().split()))
ans = 0
s = 0

for n, i in enumerate(reversed(A[1:]), 1):
    s += i
    ans += A[N-n-1] * s
    
print(ans % 1000000007)