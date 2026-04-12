X, Y, Z =map(int,input().split())
chair=0
chair+=Z
count=0
while chair<X:
    chair+=Y+Z
    count+=1
if chair>X:
    print (count-1)
else:
    print (count)