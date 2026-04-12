import itertools

N, M = (int(i) for i in input().split())
sides = []
for i in range(M):
    a, b = (int(i) for i in input().split())
    sides.append((a-1,b-1))
kouhos = list(itertools.permutations(range(N)))
count = 0

for kouho in kouhos:
    Judge = True
    if kouho[0] != 0:
        break
    else:
        for i in range(N-1):
            if (kouho[i] , kouho[i+1]) in sides:
                pass
            elif (kouho[i+1] , kouho[i]) in sides:
                pass
            else:
                Judge = False
                break
    
    if Judge:
        count += 1

print(count)


    