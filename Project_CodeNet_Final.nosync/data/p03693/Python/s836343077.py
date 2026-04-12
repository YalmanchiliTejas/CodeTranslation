r, g, b = map(str, input().split())

a=r+g+b
val=int(a)
if(val % 4 == 0):
    print ("YES")
else:
    print ("NO")
