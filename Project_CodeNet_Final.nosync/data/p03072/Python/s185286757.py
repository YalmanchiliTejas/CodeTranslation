N = int(input())
H = list(map(int, input().split()))

ans = 0
for i in range(N):
    ans += 1
    for j in range(0, i):
        if H[i] < H[j]:
            ans -= 1
            break

print(ans)