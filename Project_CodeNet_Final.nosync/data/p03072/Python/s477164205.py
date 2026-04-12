N = int(input())
h = list(map(int, input().split()))
ans, peak = 0, 0
for i in h:
    if peak <= i:
        ans += 1
        peak = i
print(ans)
