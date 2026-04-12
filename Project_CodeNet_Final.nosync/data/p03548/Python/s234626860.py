x,y,z=map(int,input().split())
n=1
while 1:
    if y*n+z*(n+1) >x:
        print(n-1)
        break
    n+=1