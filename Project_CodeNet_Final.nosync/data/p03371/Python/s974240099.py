a,b,c,x,y = map(int,input().split())

ans = a * x + b * y

for i in range(1,max(x,y)+1):
    tmp = max(0, x-i) * a + max(0, y-i) * b + 2 * c * i
    ans = min(ans,tmp)
    
print(ans)