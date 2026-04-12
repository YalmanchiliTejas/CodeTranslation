N = int(input())
H = list(map(int, input().split()))
cnt = 1
m = H[0]
for i in range(1, N):
    if m <= H[i] and H[i-1] <= H[i]:
        cnt += 1
        m = max(H[0], H[i])

print(cnt)