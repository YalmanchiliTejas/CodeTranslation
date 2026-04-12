N = int(input())

ans = 0
curM = 0

H = list(map(int, input().split()))

for h in H:
    if h >= curM:
        ans += 1
    curM = max(curM, h)
print(ans)