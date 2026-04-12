n = int(input())
h = list(map(int,input().split()))
ans = 0
for i in range(n):
    temp_max = 0
    judge = True
    for j in range(i):
        if h[i] < h[j]:
            judge = False
    if judge:
        ans += 1
print(ans)