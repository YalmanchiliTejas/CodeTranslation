n = int(input())
list_h = list(map(int, input().split()))
hight = 0
ans = 0
for i in range(n):
    if list_h[i] >= hight:
        hight = list_h[i]
        ans += 1
print(ans)