N = int(input())
H = [int(x) for x in input().split()]

ans = 0
highest = 0
for h in H:
    if h>= highest:
        ans += 1
        highest = h
print(ans)
