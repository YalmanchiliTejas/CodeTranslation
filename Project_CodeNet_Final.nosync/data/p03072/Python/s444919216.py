N = int(input())
H = [int(x) for x in input().split()]

m = H[0]
cnt = 1
for i in range(1, N):
    if H[i] >= m:
        cnt += 1
        m = H[i]
print(cnt)