import sys
input = sys.stdin.readline

a,b,c,x,y = map(int, input().split())

cost = float('inf')
mz = max(x,y)*2
for z in range(1,mz+1):
    #print(z, (a*x + b*y), a*(x-0.5*z) + b*(y-0.5*z) + c*z)
    if z > 0:
        cost = min(cost, a*max((x-0.5*z),0) + b*max((y-0.5*z),0) + c*z)
cost = int(min(cost, a*x + b*y))
print(cost)