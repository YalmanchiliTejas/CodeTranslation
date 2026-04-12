n = int(input())
h = list(map(int, input().split()))
cnt = 1
hmax = [0] * n
hmax[0] = h[0]
for i in range(1, n):
    hmax[i] = max(hmax[i - 1], h[i])
    if hmax[i] == h[i]:
        cnt +=1
print(cnt)