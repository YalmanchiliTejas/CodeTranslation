N = int(input())
H = [int(i) for i in input().split()]

ans = 0
for i in range(N):
    if max(H[:i + 1]) <= H[i]:
        ans += 1
print(ans)
