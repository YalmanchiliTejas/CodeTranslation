n = int(input())
count = 0
data = [int(s) for s in input().split()]
max = data[0]
for i in range(0,n-1):
    
    if max < data[i]:
      max = data[i]
    if data[i] <= data[i+1] and data[i+1] >= max:
        count += 1


print(count+1)

    
    