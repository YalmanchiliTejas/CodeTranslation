n = int(input())
mountain = [ int(s) for s in input().split(" ")]
ans = 0
highest = 0

for m in mountain:
    if m >= highest:
        ans += 1
        highest = m

print(ans)
