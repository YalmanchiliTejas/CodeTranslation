a,b,c,x,y = map(int, input().split())
cost = [a*x+b*y]
cost.append(c*2*x+b*max((y-x),0))
cost.append(c*2*y+a*max((x-y),0))
cost.append(c*2*max(x,y))
print(min(cost))