X,Y,Z=map(int,input().split())
p=1
w=Y+Z*2

while w<=X:
    w+=Y+Z
    p+=1

print(p-1)