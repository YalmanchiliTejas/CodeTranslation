n = int(input())
h = list(map(int, input().split()))
sea = []
mountain = h[0]
for i in range(n):
    if i == 0:
        sea.append(h[0])
    else:
        if h[i] >= mountain and h[i] >= h[0]:
            mountain = h[i]
            sea.append(h[i])
        
print(len(sea))