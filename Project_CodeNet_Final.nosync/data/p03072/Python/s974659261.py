#B

n = int(input())
H = [int(x) for x in input().split()]

count = 0
maxh = 0
for i in H:
    if i >= maxh:
        count += 1
        maxh = i
        
print(count)
