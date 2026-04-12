N=int(input())
s=input()
animals = ["" for _ in range(N)]

def convert(animal):
    if animal == "S":
        return "W"
    else:
        return "S"

def animalOnRight(left,center,sig):
    if center == "S":
        if sig == "o":
            return left
        else:
            return convert(left)
    else:
        if sig == "o":
            return convert(left)
        else:
            return left
for (a0,a1) in [("W","S"),("W","W"),("S","S"),("S","W")]:
    animals[0],animals[1] = (a0,a1)
    for i in range(N-2):
        animals[i+2] = animalOnRight(animals[i],animals[i+1],s[i+1])
        #print(animals)
    satisfied = (animalOnRight(animals[N-2],animals[N-1],s[N-1]) == animals[0]) and (animalOnRight(animals[N-1],animals[0],s[0]) == animals[1])
    if satisfied:
        for char in animals:
            print(char, end='')
        print()
        exit()
print(-1)
