N = int(input())
hotel = list(map(int, input().split()))
count = 0
c = 0
for i in range(1, N):
    c=0
    for j in range(0, i):
        
        if hotel[i] >= hotel[j]:
            c += 1
        if c == i:
            count += 1
print(count+1)
