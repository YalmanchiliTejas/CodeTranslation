import sys
input = sys.stdin.readline

A, B, C, X, Y = map(int, input().split(' '))

ans = 2 * 100000 * 5000
for i in range(10**5+1):
    price = 2*C*i + A*max(0, X-i) + B*max(0, Y-i)
    ans = min(ans, price)
print(ans)