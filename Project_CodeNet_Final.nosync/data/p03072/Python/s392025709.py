n=int(input())
height=list(map(int,input().split()))
count=0
for i in range(0,n):
    for j in range(0,i+1):
        if height[i]<height[j]:
            break
        if j==i:
            count+=1
print(count)
