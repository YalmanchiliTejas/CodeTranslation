N = int(input())
inpl = list(map(int,input().split()))
for i in range(len(inpl)):
    for i2 in range(i,-1,-1):
        if inpl[i] < inpl[i2]:
            N -= 1
            break
print(N)