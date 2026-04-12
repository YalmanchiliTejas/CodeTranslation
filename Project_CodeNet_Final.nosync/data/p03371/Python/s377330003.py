a,b,c,x,y = map(int, input().split())

d = c*2*x+b*(y-x) if y>x else c*2*y + a*(x-y)

print(min(a*x+b*y, c*2*max(x,y),d))