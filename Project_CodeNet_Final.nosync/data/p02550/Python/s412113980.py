n, x, m = map(int,input().split())
ans = x
num = 0
l = [0]*m
lis = [-1]*m
l[0] = x
lis[x] = num
for i in range(1,n):
    x = (x*x)%m
    num += 1
    if lis[x]!=-1:
        a = (n-i)//(i-lis[x])
        b = (n-i)%(i-lis[x])
        ans += a * sum(l[lis[x]:i])
        for j in range(lis[x],lis[x]+b):
            ans += l[j]
        break
    l[i] = x
    lis[x] = i
    ans += x
print(ans)