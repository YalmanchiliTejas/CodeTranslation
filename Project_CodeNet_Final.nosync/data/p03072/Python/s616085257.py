n = int(input())
li = list(map(int, input().split()))
ans = 0
for i in range(n):
    flag=True
    for j in range(i):
        if li[i] < li[j]:
            flag = False
    if flag == True:
        ans += 1
print(ans)