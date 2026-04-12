n = int(input())
H = [int(i) for i in input().split()]

ma = 0
ans = 0
for h in H:
    if ma <= h:
        ans += 1
        ma = h

print(ans)