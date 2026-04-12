N = int(input())
H = list(map(int, input().split()))

max_tmp = 0
ans = 0
for i, h in enumerate(H):
    if h >= max_tmp:
        ans += 1
        max_tmp = h

print(ans)