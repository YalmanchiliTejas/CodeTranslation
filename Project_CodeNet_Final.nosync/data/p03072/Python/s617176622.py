N = int(input())
H = list(map(int, input().split()))

ans = 0
for i in range(N):
    can_see = True
    for j in range(i):
        can_see &= (H[j] <= H[i])
    if can_see:
        ans += 1

print(ans)
