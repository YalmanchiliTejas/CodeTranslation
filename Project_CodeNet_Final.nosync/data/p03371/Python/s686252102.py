a,b,c,x,y = map(int,input().split())

sum = a * x + b * y
s = [sum]
for i in range(max(x,y)):
    if (x>0) and (y>0):
        x -= 1
        y -= 1
        sum = sum + (2 * c - a - b)

    elif (x>0):
        x -= 1
        sum = sum + (2 * c - a)

    elif (y>0):
        y -= 1
        sum = sum + (2* c - b)

    s.append(sum)
    #print(sum)
print(min(s))