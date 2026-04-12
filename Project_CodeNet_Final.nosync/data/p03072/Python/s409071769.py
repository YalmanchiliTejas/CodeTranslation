N = int(input())
H = list(map(int, input().split()))

ans = 0
before_max = 0
for i in range(N):
    if H[i] >= before_max:
        ans += 1
    before_max = max(before_max, H[i])

print(ans)