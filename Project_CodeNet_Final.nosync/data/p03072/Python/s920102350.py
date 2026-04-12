n = int(input())
h = [int(_) for _ in input().split()]
ans = 0

for i, x in enumerate(h):
    for j in range(i):
        if h[j] > x:
            break
    else:
        ans += 1

print(ans)
