import sys
input = sys.stdin.readline
n = int(input())
A = [int(input()) for i in range(n)]
A.sort()
ans = 0
for i in range(n//2):
    ans += (A[i+1]-A[i])*2*(i+1)
    ans += (A[n-1-i]-A[n-1-i-1])*2*(i+1)
    # print(A[i+1], A[i], 2*(i+1))
    # print(A[n-1-i], A[n-1-i-1], 2*(i+1))
if n % 2 == 1:
    ans -= min(A[n//2]-A[n//2-1], A[n//2+1]-A[n//2])
else:
    ans -= (A[n//2] - A[n//2-1]) * (2 * (n//2) + 1)
print(ans)