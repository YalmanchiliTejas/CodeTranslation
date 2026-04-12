N = int(input())
H = list(map(int, input().split()))
cnt = 0
front = 0
for i in range(N):
    if front <= H[i]:
        cnt += 1
    front = max(front, H[i])
print(cnt)