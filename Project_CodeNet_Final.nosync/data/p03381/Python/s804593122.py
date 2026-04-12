N = int(raw_input())
X = map(int, raw_input().split())

sortedX = sorted(X)
medSmall = sortedX[N/2-1]
medLarge = sortedX[N/2]

#print medSmall, medLarge

for i in range(N):
    if(X[i] <= medSmall):
        print(medLarge)
    else:
        print(medSmall)
