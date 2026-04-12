N = int(input())
h = list(map(int, input().split()))

ans = 1
for i in range(1, N):
    for j in range(i):
        if h[i] < h[j]:
            break
    else:
        ans += 1
print(ans)
