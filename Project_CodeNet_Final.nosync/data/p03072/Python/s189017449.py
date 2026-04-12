N=int(input())
listH = list(map(int,input().split()))
output = 1
maxH = listH[0]
for i in range(1,N):
    if listH[i]>=maxH:
        maxH = listH[i]
        output += 1
print(output)