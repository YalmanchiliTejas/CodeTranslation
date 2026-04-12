x,y,z=map(int,input().split())
ans=0
for i in range(x):
    if x>=i*(y+z)+z and i>ans:
        ans=i
print(ans)