N = int(input())
H = list(map(int, input().split()))

cnt = 0
max = 0
for i in range(N):
    if H[i] >= max:
        max = H[i]
        cnt += 1
    else:
        max = max
        cnt = cnt

print(cnt)