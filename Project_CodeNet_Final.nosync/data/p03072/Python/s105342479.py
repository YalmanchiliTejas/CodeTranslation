n = int(input())
h = list(map(int,input().split()))
ans = 0
u = 0
for i in range(n):
    for j in range(i):
        if h[i] < h[j]:
            u = 1
            break
    if u == 0:
        ans += 1
    elif u == 1:
        u = 0
print(ans)