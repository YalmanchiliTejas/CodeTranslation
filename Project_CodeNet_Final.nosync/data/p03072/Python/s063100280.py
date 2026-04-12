n = int(input()) 
mountains = list(map(int, input().split()))
maxHeight = 0
x = 0
for h in mountains:
    if h >= maxHeight:
        x += 1
    maxHeight = max(h, maxHeight)
print(x)