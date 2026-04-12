import sys
sys.setrecursionlimit(4100000)

a,b,c,x,y = [int(i) for i in input().split()]
cost = x * a
while y != 0:
    if x > 0:
        if c * 2 < a + b:
            cost += -a + c*2
            y -= 1
            x -= 1
        else:
            cost += b
            y -= 1
    else:
        if b < c * 2:
            cost += b
            y -= 1
        else:
            cost += c*2
            y -= 1
print(cost)
