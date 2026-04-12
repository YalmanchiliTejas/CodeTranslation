import sys
A, B, C, x, y = map(int, sys.stdin.readline().split())

ans = float('inf')
for i in range(0, 2*max(x, y)+1, 2):
    tmp = A*max(x-i//2, 0) + C*i + B*max(y-i//2, 0)
    if tmp < ans:
        ans = tmp
print(ans)