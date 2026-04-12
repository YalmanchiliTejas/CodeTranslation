N = int(input())
H = map(int, input().split())
ans = 0
high = 0
for h in H:
    if high <= h:
        ans += 1
        high = h
print(ans)
