N = int(input())
H = list(map(int, input().split()))

highest = -float("inf")
ans = 0

for h in H:
    if highest <= h:
        highest = h
        ans += 1
print(ans)
