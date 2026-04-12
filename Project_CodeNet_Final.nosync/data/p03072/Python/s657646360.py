N=int(input())
H=[int(i) for i in input().split()]
hotel=0
for i in range(N):
    count=0
    for k in range(i):
        if H[k]<=H[i]:
            count+=1
        continue
            
    if count==i:
        hotel+=1


print(hotel)
