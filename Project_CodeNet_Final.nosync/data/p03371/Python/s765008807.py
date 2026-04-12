#C
a, b, c, x, y = map(int,input().split())
ans = 10**10
for i in range(10**5+1):
    ans = min(ans,2*c*i + a*max(0,x-i) + b*max(0,y-i))
print(ans)