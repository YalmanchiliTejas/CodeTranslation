a, b, c, x, y = map(int, input().split())

if x>=y:
    print(min(a*x+b*y, c*x*2, c*y*2+a*(x-y)))
elif x<y:
    print(min(a*x+b*y, c*y*2, c*x*2+b*(y-x)))