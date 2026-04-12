x,y,z=map(int,input().split())
cnt=x//(y+z)
print(cnt if cnt*(y+z)+z<=x else cnt-1)