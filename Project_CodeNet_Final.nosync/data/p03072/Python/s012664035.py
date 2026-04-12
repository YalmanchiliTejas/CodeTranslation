n = int(input())
H = list(map(int, input().split()))

h_max = 0
ans = 0
for h in H:
    if h >= h_max:
        ans += 1
        h_max = h
print(ans)