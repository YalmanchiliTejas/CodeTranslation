N = int(input())
H = list(map(int, input().split()))

h_max_till_i = 0
ans = 0
for i in range(N):
    if H[i] >= h_max_till_i:
        ans += 1
        h_max_till_i = H[i]

print(ans)
