
N = int(input())
H = list(map(int, input().split()))
ans = 1

for i in range(1, N):
    key = 0
    for j in range(i):
        if H[j] > H[i]:
            key = 1
            break
    if not key:
        ans += 1

print(ans)