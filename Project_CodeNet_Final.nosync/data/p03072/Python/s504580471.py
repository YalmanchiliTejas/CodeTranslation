N = int(input())
H = list(map(int, input().split()))

hight = 0
ans = 0

for i in H:
    if i >= hight:
        hight = i
        ans += 1

print(ans)
