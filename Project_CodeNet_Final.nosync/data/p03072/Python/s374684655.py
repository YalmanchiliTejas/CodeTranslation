n = int(input())
h = list(map(int,input().split(" ")))
ans = 1
for i in range(1,n):
    tmp = 1
    for j in range(i):
        if h[j] <= h[i]:
            continue
        else:
            tmp = 0
            break;
    if tmp == 1:
        ans += 1
print(ans)
