N = int(input())
H = list(map(int, input().split()))

max_h = 0
cnt = 0
for n in range(N):
    if max_h <= H[n]:
        cnt += 1
        max_h = H[n]

print (cnt)
