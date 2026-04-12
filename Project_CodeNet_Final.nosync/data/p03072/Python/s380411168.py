N = (int(i) for i in input().split()) 
H = [int(i) for i in input().split()]

highest = 0
can_sea_hotels = 0

for i in range(len(H)):
    if highest <= H[i]:
        highest = H[i]
        can_sea_hotels += 1
    
print(can_sea_hotels)  