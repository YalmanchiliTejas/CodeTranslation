a, b, c, x, y = map(int, input().split())

ab=c*2
n=max(x, y)+1
res=1145141919
for i in range(n):
    res=min(res, i*ab+max(0,x-i)*a+max(0,y-i)*b)
print(res)
