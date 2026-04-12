N = int(input())
H = list(map(int, input().split()))
m = -1
cnt = 0
for i in range(N):
    m = max(m, H[i])
    if m == H[i]:
        cnt += 1

print(cnt)