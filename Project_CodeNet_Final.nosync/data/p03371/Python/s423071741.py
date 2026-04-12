A,B,C,X,Y = map(int,input().split())

minValue = float('inf')

for i in range(0,100001):
    total = 2 * i * C + max([0,X-i]) * A + max([0,Y-i]) * B
    
    if minValue > total:
        minValue = total

print(minValue)
