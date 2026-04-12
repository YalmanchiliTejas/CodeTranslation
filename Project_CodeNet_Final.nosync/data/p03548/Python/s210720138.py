x,y,z=map(int,input().split())
j=1
while 1:
    if x < y*j+z*(j+1):
        print(j-1)
        break
    j+=1