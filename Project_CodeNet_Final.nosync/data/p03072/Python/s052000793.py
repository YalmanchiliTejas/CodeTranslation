n = int(input())
lista = [int(x) for x in input().split()]
maxi = 0
res = 0
for i in range (0, len(lista)):
  if lista[i]>=maxi:
    res+=1
    maxi = lista[i]
print(res)