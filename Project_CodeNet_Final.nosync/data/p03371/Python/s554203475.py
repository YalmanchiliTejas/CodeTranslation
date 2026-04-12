a,b,c,x,y = map(int, input().split())
ans = a*x + b*y
for i in range(1, max(x,y)+1):
    if (max((x-i),0)*a + max((y-i),0)*b + c*2*i) < ans:
        ans = (max((x-i),0)*a + max((y-i),0)*b + c*2*i)
print(ans)
