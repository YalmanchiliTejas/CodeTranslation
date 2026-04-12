N = int(input())
H = list(map(int, input().split()))

ans = 0
b = 0
for i in range(N):
    if H[i] >= b:
        ans += 1
        b = H[i]

print(ans)