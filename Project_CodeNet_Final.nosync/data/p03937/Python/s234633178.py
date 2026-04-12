h,w=map(int,input().split())
count=0
for i in range(h):
    for j in input():
        if j == "#" : count+=1
print("Possible") if count==h+w-1 else print("Impossible")