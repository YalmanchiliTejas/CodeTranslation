n = int(input())
h = tuple(map(int, input().split()))
ans = 0
for i in range(n):
    for j in range(i):
        if h[j] > h[i]:
            break
    else:
        ans += 1
print(ans)
