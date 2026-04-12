X,Y,Z = map(int,input().split())

p = 0
cap = Z
while(True):
    if cap>X:
        break
    elif cap+Y+Z>X:
        break
    else:
        cap += Y+Z
        p += 1
        
print(p)