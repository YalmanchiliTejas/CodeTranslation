a,b,c,x,y = map(int,input().split())

ans = float('inf')
for i in range(0,2*max(x,y)+1,2):
    ab = i
    x_tmp = x - i//2
    y_tmp = y - i//2
    tmp = max(0,a*x_tmp) + max(0,b*y_tmp) + c*i
    if tmp < ans:
        ans = tmp
print (ans)
