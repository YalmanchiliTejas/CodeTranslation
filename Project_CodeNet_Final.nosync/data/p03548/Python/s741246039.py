x,y,z=map(int,input().split())

n=0
while(1):
    if(n*y+(n+1)*z>x):
        break
    n+=1

print(n-1)