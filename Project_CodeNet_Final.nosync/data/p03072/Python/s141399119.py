n = int(input())
h = list(map(int,input().split()))
ans = 1
for i in range(1,n):
    flag = True
    for j in range(0,i):
        if h[i] < h[j]:
            flag = False
            break
    if flag:ans += 1
print(ans)