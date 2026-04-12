N = int(input())
H = list(map(int, input().split()))

ans = 1

for i in range(1, N):
    ans += max(H[0:i]) <= H[i]

print(ans)