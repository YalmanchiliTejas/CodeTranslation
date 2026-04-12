n = int(input())
h = list(map(int, input().split()))
current_big = 0
ans = 0
for i in h:
    if i >= current_big:
        current_big = i
        ans += 1
print(ans)
