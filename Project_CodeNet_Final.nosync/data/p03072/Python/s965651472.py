n = int(input())
pousadas = [int(x) for x in input().split()]
maior = 0
cont = 0
for i in pousadas:
    if (maior - i) <= 0:
        cont += 1
        maior = i
print(cont)
