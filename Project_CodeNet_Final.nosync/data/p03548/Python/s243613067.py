X,Y,Z = map(int,input().split())
count = 0
wide = Z+Y+Z
while X >= wide:
    count+=1
    wide +=Z+Y
print(count)
