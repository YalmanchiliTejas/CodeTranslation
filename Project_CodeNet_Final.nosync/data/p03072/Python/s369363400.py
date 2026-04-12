N = int(input())
H = [int(h) for h in input().split()]
maxh = H[0]
cnt = 1
for i in range(1, N):
    if H[i] >= maxh:
        cnt += 1
        maxh = H[i]
print(cnt)
