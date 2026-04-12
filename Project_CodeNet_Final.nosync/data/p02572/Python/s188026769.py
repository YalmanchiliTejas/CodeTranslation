n = int(input())
A = list(map(int, input().split()))
a = [0]
ans = 0

for i in range(n-1):
    a.append(a[i] + A[i])
for i in range(n):
    ans += A[i]*a[i]
print(ans % (10**9 + 7))
