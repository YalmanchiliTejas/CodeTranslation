
[X,Y,Z] = list(map(int,input().split()))

i=0
while True:
    need= i*Y + (i+1)*Z
    if need>X:
        break
    i+=1

print(i-1)
