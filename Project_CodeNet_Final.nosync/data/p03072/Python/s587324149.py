n = int(input())
h = [int(i) for i in input().split()] 
max=0
ans=0

for i in h:
    if i >= max:

        ans+=1
        max=i
print(ans)
