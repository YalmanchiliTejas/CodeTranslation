n = int(input())
h = list(map(int,input().split()))
ans = 1
for i in range(1,n):
    flag = 1
    for j in range(i):
        if h[j] > h[i]:
            flag = 0
            break
        else:
            pass
    if flag:
        ans += 1
print(ans)
