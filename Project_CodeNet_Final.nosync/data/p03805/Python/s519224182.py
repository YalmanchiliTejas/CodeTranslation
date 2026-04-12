import itertools

N, M = map(int, input().split())

sides = []

for _ in range(M):
    temp_a, temp_b = map(int, input().split())
    sides.append(set([temp_a, temp_b]))



#print(sides)
counter = 0
for i in itertools.permutations(range(1, N+1)):
    if i[0] != 1:
        continue

    for j in range(0,N-1):
        if set([i[j],i[j+1]]) in sides:
            continue
        else:
            break
    else:
        counter += 1
        continue
    


print(counter)

