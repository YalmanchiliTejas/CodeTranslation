N = int(input())
H = list(map(int, input().split()))
cnt = 0
maxH = H[0]

for m in range(1,N):
    if H[m] - maxH >= 0:
        maxH = H[m]
        cnt += 1

print(cnt+1)