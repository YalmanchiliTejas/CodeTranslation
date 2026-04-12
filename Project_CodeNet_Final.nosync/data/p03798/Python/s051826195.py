n=int(input())
s=input()
animals=["#"]*len(s)

def oppositeAnimal(animal):
  if animal=="S":
    return "W"
  else:
    return "S"

def getNextAnimal(animal,answer,pastanimal):
  if animal=="S":
    if answer=="o":
      return pastanimal
    else:
      return oppositeAnimal(pastanimal)
  else:
    if answer=="o":
      return oppositeAnimal(pastanimal)
    else:
      return pastanimal

for a0 in ("S","W"):
  for a1 in ("S","W"):
    animals=["#"]*len(s)
    animals[0]=a0
    animals[1]=a1
    for i in range(2,len(s)):
      animals[i]=getNextAnimal(animals[i-1],s[i-1],animals[i-2])
    if getNextAnimal(animals[len(s)-1],s[len(s)-1],animals[len(s)-2])==animals[0]:
      if getNextAnimal(animals[0],s[0],animals[len(s)-1])==animals[1]:
        print("".join(animals))
        exit(0)
print(-1)