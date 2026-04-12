a,b,c,x,y = map(int,input().split())
ans = 10**20
for k in range(max(x,y)+1):
    tmp = 2*c*k + max(x-k,0)*a + max(y-k,0)*b
    ans = min(ans,tmp)
print(ans)
