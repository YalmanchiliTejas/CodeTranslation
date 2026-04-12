a,b,c,x,y = map(int,input().split())
c *= 2
ans = 10 ** 16
for i in range(max(x,y) + 1):
    p = 0
    p += c * i
    p += a * (max(0,x - i))
    p += b * (max(0,y - i))
    ans = min(ans,p)
print(ans)