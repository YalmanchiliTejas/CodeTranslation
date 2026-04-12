N = int(input())
High = list(map(int, input().split()))

now = 0
ans = 0
for h in High:
    if now <= h:
        ans += 1
        now = h
print(ans)