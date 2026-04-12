x,y,z=map(int,input().split())
l=[]
for i in range(x):
    if (x-((z+y)*i+z))>=0:
        l.append(i)
print(max(l))
