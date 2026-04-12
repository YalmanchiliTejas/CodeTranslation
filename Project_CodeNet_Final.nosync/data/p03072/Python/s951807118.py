trip = int(input())
sumiit = [int(i) for i in input().split()]
count = 1
for i in range(1, trip):
    jug = []
    for n in range(0, i):
        if sumiit[n] <= sumiit[i]:
            jug.append(True)
        else:
            jug.append(False)
    if all(jug):
        count += 1
print(count)

