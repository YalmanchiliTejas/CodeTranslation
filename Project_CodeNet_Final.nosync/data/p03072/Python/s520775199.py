N = int(input())
H = list(map(int, input().split()))

h_max = H[0]
cnt = 0
for i in range(N):
    if H[i] >= h_max:
        cnt += 1
        h_max = H[i]
print(cnt)