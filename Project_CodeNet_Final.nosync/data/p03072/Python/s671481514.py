import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())

H = list(map(int, input().split()))

maximum = 0
ans = 0 
for i in range(N):
    if H[i] >= maximum:
        ans += 1
        maximum = H[i]

print(ans)