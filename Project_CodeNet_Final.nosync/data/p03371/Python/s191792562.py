a,b,c,x,y = map(int, input().split())
minv = min(x,y)
ans = a*x + b*y
for i in range(1,max(x,y)+1):
    if i <= minv:
        ans = min(ans, a*(x-i)+b*(y-i)+c*2*i)
    elif i == max(x,y):
        ans = min(ans, c*2*i)
print(ans)