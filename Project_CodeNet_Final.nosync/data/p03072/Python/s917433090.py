N = int(input())
H = list(map(int, input().split()))

highest = 0
ans = 0
for h in H:
    if h >= highest:
        ans += 1
        highest = h
print(ans)
