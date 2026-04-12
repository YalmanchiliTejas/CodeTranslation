
Num = int(input())
Hights = input().split()
hotels = 0

curHight = 0

for i in range(Num):
    if curHight <= int(Hights[i]):
        hotels+=1
        curHight = int(Hights[i])
        
print(hotels)

