a,b,c,x,y = map(int,input().split())

ans = min(a*x+b*y, c*x*2+b*max(0, y-x), a*max(0, x-y)+c*y*2)
print(ans)
