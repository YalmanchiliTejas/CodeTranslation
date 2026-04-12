mon = int(input())
top = 0
ocean = 0
hight = list(map(int, input().split()))
for i in range(mon):
    if hight[i] >= top:
        ocean+=1
        top = hight[i]
print(ocean)