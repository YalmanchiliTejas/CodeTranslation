N = int(input())
H = list(map(int, input().split()))
maxH = 0
ans = 0
for i in H:
    if i >= maxH:
        maxH = i
        ans += 1
print(ans)