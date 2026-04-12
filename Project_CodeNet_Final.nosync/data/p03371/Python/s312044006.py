a,b,c,x,y = map(int,input().split())
ans = 10**18
for i in range(10**5+1):
    temp = 2*i*c + max(0,x-i)*a + max(0,y-i)*b
    ans = min(ans,temp)
print(ans)
