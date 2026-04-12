N = int(input())
H = list(map(int, input().split()))

tmp = 0
ans = 0
for h in H:
    if h >= tmp:
        ans += 1
        tmp = h

print(ans)