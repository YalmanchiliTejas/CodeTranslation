N = int(input())
H = [int(i) for i in input().split()]

ans = 1
cur_max = H[0]
for h in H[1:]:
    if h >= cur_max:
        ans += 1
    cur_max = max(cur_max, h)

print(ans)