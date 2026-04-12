a,b,c,x,y = map(int,input().split())
ans = float('inf')
for i in range(0,max(x,y)+1):
    ans = min(ans, i*2*c + max(0,x-i)*a + max(0,y-i)*b)
print(ans)