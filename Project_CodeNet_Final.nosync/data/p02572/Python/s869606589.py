N = int(input())
A = list(map(int, input().split()))

from itertools import combinations

num = 10**9 + 7
ans = 0

B = []
b = 0
for i in reversed(A[1:]):
    b += i
    B.append(b)
B.reverse()
for x, y in zip(A[:-1], B):
    ans += x*y
    ans %= num
print(ans)
