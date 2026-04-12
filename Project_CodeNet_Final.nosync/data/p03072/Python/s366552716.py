N = int(input())
H = list(map(int, input().split()))

cnt = 1
max_v = H[0]
for i in range(1, N):
    if H[i] >= max_v:
        cnt += 1
        max_v = H[i]
print(cnt)
