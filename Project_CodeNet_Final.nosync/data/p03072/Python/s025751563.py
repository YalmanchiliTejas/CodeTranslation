num_hotels = int(input())
num_oceanview_hotel = 1
mountains = list(map(int,input().split()))
max_mountain = mountains[0]

for i in range(1, num_hotels):
    if mountains[i] >= max_mountain:
        max_mountain = mountains[i]  
        num_oceanview_hotel += 1
        
print(num_oceanview_hotel)