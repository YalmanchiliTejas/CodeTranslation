n = input()
heights = map(int,input().split(" "))
highest = -1
ans = 0
for h in heights:
    if h >= highest:
        ans += 1
        highest = h
print(ans)