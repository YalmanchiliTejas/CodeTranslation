N = int(input())
H = list(map(int,input().split()))
ans = 0
for i in range(N):
    h = H[i]
    flag = True
    for j in range(i+1):
        if h < H[j]:
            flag = False
            break
    if flag == True:
        ans += 1
print(ans)

