n = int(input())
l = list(map(int, input().split()))

ans = 1
flg = False
for i in range(n):
    for j in range(i):
        if l[i] >= l[j]:
            flg = True
            continue
        else:
            flg = False
            break
    if flg == True: ans += 1  

print(ans)