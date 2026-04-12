n = int(input())
line = input()
lista = [int(n) for n in line.split()]
pos = 1
can = 0
for l in lista:
    semi_lista = lista.copy()
    semi_lista = semi_lista[0:pos]
    semi_lista.sort()
    step_max = semi_lista[len(semi_lista)-1]
    if l >= step_max:
        can+=1
    pos+=1
print(can)