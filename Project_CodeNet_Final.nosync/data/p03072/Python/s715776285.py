#ABC124B
n = int(input())
h = list(map(int, input().split()))
max_height = 0
count = 0

for i in range(n):
    if h[i] >= max_height:
        max_height = h[i]
        count = count + 1
    else:
        pass
    
print(count)