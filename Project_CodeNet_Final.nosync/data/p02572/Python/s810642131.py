N = int(input())
C = 10 ** 9 + 7
B = 0
a = 0
ans = 0
A = list(map(int, input().split()))
for i in range(N):
    a += A[i]
for i in range(N-1):
    a -= A[i]
    B = A[i] * a
    ans += B
    B = 0    
print(ans % C)        

