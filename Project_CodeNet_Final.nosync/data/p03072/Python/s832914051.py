N = int(input())
H = [int(i) for i in input().split()]
ans = 0
l = 0
for x in H:
    if l <= x:
        ans += 1
        l = max(l, x)
print(ans)