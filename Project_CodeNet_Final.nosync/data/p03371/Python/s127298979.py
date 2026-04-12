a,b,c,x,y = map(int, input().split())

ans = 10**18
for k in range(2*10**5+1):
    if k%2 != 0:
        continue
    i = max(x-k//2, 0)
    j = max(y-k//2, 0)
    temp = a*i+b*j+c*k
    ans = min(ans, temp)
print(ans)
