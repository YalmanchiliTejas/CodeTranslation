n = int(input())
a = list(map(int, input().split()))
A = [0]*(n)
num = 1000000007
ans = 0
for i in range(1, n):
    A[i] = int((A[i-1] + a[i-1])%num)
for i in range(n-1, 0, -1):
    ans += int((A[i]*a[i])%num)
    ans = int(ans % num)
print(int(ans))