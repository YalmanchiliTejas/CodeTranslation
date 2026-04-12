N = int(input())
H = [int(_) for _ in input().split()]
yama = 0
ans = 0
for i in H:
    if yama <= i:
        ans += 1
        yama = i

print(ans)