input = input()
split = input.split()
pliceA = int(split[0])
pliceB = int(split[1])
pliceC = int(split[2])
neededA = int(split[3])
neededB = int(split[4])

maxC = neededA * 2 if neededA > neededB else neededB * 2
minPlice = 10 ** 10
for c in range(0, maxC + 1, 1):
    leftA = neededA - int(c / 2) if neededA - int(c / 2) > 0 else 0
    leftB = neededB - int(c / 2) if neededB - int(c / 2) > 0 else 0
    plice = leftA * pliceA + leftB * pliceB + pliceC * c
    minPlice = plice if plice < minPlice else minPlice

print(minPlice)