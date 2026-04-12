n = int(input())
h = list(map(int,input().split()))
ans = 1
for i in range(1,n):
    t = True
    for j in range(i):
        if h[j] > h[i]:
            t = False
    if t:
        ans += 1

print(ans)