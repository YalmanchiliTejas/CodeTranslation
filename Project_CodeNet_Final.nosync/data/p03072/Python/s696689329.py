N = int(input())
H = list(map(int, input().split()))

mi = H[0]

ans = 0

for i in H:
    if mi <= i:
        ans += 1
        mi = i


print(ans)