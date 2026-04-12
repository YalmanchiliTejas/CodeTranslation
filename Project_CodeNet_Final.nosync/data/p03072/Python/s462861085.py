N = int(input())
H = list(map(int, input().split()))
c = 1
maxh = H[0]
for i in range(1, N):
    if maxh <= H[i] and H[i - 1] <= H[i]:
        c += 1
    maxh = max(maxh, H[i])
print(c)