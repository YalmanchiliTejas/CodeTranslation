n = int(input())
mount = list(map(int, input().split()))
count =1
for i in range(1,n):
    for j in range(0,i):
        if mount[i] >= mount[j] and j != i-1:
            continue
        elif mount[i] >= mount[j] and j == i-1:
            count+=1
        else:    
            break
print(count)