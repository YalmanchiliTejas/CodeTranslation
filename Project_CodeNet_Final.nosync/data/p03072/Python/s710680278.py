N=int(input())

mount=list(map(int,input().split()))

max_height=0
count=0
for x in range(len(mount)):
    if mount[x] >= max_height:
            count+=1
            max_height=mount[x]

print(count)