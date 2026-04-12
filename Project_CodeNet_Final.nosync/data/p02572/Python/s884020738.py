N = int(input())
A = list(map(int,input().split()))
sum = 0
ans = 0
for i in range(1, N):
   sum +=A[i-1]
   sum = sum % (10**9 + 7)
   ans = ans + (sum * A[i]) % (10**9 + 7)
   ans = ans % (10**9 + 7)
print(ans)