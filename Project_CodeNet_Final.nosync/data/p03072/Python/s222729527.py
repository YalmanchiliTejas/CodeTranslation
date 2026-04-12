n = int(input())
h = list(map(int, input().split()))

ans = 0
h_max = 0
for h_i in h:
    if h_max <= h_i:
        ans += 1
        h_max = h_i
print(ans)
