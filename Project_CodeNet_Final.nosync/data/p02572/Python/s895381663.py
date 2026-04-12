d = 10 ** 9 + 7
n = int(input())
lista = [int(x) for x in input().split()]
for k in lista:
    k %= d

totalJ = sum(lista)

total = 0
for i in range(n-1):
    totalJ -= lista[i]
    total += totalJ * lista[i]
total %= d
print(total)

