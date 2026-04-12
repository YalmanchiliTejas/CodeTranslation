N = int(input())
H = [int(i) for i in input().split()]

ans = 1
for i in range(1, N):
    if H[i] >= max(H[:i]):
        ans += 1
print(ans)
