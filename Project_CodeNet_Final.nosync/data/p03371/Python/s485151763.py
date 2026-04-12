A,B,C,X,Y = (int(i) for i in input().split())

if X>=Y:
    bigger = A
else:
    bigger = B


common = max(X,Y) - abs(X-Y)
if (A+B)/2 < C:
    total = A*common + B*common
else:
    total = C*common*2

difference = abs(X-Y)
if bigger < C*2:
    total = total + bigger*difference
else:
    total = total + difference*C*2


print(total)