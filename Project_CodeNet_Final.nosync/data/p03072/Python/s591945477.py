N = int(input())
H = [int(x) for x in input().split()]

tmp = 0
ans = 0

for h in H:

    if h >= tmp:
        tmp = h
        ans += 1

print(ans)