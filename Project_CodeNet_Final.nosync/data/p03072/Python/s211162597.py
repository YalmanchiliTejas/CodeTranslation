x = int(input()) # 1 2
h = list(map(int,input().split()))
count = 0
height = 0
for i in range(len(h)):
    if h[i] >= height:
        count += 1
        height = h[i]

print (count)
