N, = (int(x) for x in input().split())
H_arr = [int(x) for x in input().split()]

ans = 0
max_H = 0
for H in H_arr:
    if H >= max_H:
        ans += 1
    max_H = max(max_H, H)

print(ans)

