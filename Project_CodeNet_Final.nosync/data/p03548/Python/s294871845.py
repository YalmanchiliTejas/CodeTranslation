x,y,z = map(int,input().split())
b = 0
for i in range(1,x+1):
    a = (i*(y+z))+z
    #print(x/a)
    if a>x:
        print(b)
        break
    else:
        b+=1