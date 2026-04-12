N = int(input())
H = list(map(int, input().split()))


H_max = 0
ans = 0
for h in H:
    if H_max <= h:
        H_max = h
        ans += 1

print(ans)
