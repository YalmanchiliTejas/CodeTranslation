n = int(input())
H = [int(h) for h in input().split()]
ans = 1
isView = False
for i in range(1,n):
    tmp = H[i]
    for j in H[:i]:
        if j > tmp:
            isView = False
            break
        else:
            isView = True
    if isView:
        ans += 1
print(ans)
