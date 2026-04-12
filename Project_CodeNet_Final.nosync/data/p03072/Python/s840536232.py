N = int(input())
H = list(map(int, input().split()))

ans = 0
for i in range(N):
    if i == 0:
        ans += 1
    else:
        if all(H[i] >= H[j] for j in range(i)):
            ans += 1
print(ans)