N = int(input())
H = list(map(int, input().split()))
ans = 1
h_max = H[0]
for i in range(1, N):
    if h_max <= H[i]:
        ans += 1
        h_max = H[i]
print(ans) 