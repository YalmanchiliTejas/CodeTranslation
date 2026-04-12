N = int(input())
H = list(map(int, input().split()))
ans = 0

for i in range(N):
    ans += 1
    if i == 0:
        continue
    for j in range(i):
        if H[j] > H[i]:
            ans -= 1
            break

print(ans)