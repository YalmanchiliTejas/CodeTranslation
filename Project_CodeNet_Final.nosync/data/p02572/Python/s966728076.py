N = int(input())
A = list(map(int, input().split()))
 
ans = 0
x = sum(A)
 
for i in range(N - 1):
    x -= A[i]
    ans += A[i] * x
    
ans = ans % (10 ** 9 + 7)
 
print(ans)