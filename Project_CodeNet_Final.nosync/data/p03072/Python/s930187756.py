n = int(input())
h = list(map(int, input().split()))

ans = 0
for num, i in enumerate(h):
    add = True
    for j in range(num):
        if h[j] > i:
            add = False
    if add:
        ans += 1

print(ans)