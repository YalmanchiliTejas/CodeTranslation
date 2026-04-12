N = int(input())
H = list(map(int, input().split()))

maxHeight = 0
cnt = 0
for i in range(N):
    if H[i]>=maxHeight:
        maxHeight = H[i]
        cnt += 1
print(cnt)