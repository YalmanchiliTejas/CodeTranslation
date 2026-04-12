n = int(input())
l = list(map(int,input().split()))
last = l[0]
dem = 1
for i in range(1,len(l)):
    if l[i] >= last:
        last = l[i]
        dem+=1
print(dem)