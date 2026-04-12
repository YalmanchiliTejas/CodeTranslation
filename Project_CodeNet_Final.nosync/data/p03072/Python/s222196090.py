import sys, copy
input = sys.stdin.readline
N = int(input())
H = [int(x) for x in input().split()]
max, ans = H[0], 1
for i in range(1,N):
    if max <= H[i]:
        ans += 1
        max = H[i]
print(ans)
