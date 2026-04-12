n,x,m = map(int,input().split())
exist = [0] * (m+1)
ans = 0
imamade = []
cnt = 0
for i in range(1,n+1):
    if exist[x] == 1:
        break
    else:
        ans += x
        exist[x] = 1
        imamade.append(x)
        x *= x
        x %= m
        cnt += 1
    if i == n:
        print(ans)
        exit()
num = imamade.index(x)
print(sum(imamade[:num]) + sum(imamade[num:]) * ((n-num) // (cnt-num)) + sum(imamade[num:num+((n-num) % (cnt-num))]))
