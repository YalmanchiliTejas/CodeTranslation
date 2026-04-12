N = int(input())
H = list(map(int, input().split()))
cnt = 1
max_height = H[0]
for i in range(1, N):
    if H[i] >= max_height:
        cnt += 1
        max_height = H[i]
print(cnt)