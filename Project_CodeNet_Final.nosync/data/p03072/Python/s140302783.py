N=int(input())
List = [int(i) for i in input().split()]

tempmax = 0
count = 0

for i in range(N):
    if List[i] >= tempmax:
        count += 1
        if List[i] > tempmax:
            tempmax = List[i]
print(count)