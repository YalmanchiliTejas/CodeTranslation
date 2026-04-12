N = int(input())
myArray = [int(x) for x in input().split()]
counter = 1

for n in range(1,N):
    if myArray[n] >= max(myArray[:n]):
        counter += 1

print(counter)