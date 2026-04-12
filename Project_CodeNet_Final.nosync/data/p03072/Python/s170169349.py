n = int(input())
h = list(map(int, input().split()))
ans = 0

for i in range(n):
    t = h[i]
    for j in range(i):
        if t < h[j]:
            break
    else :
        ans += 1

print(ans)