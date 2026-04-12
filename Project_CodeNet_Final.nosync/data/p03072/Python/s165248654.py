N = int(input())
H = list(map(int, input().split()))
cnt = 0
canSee = H[0]
for i in range(N):
    if H[i] >= canSee:
        canSee = H[i]
        cnt += 1
print(cnt)
