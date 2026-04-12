lista = []
contador = 0
entrou = 0
nVezes = int(input())
linha = input()
lista = linha.split()
for aux in range(len(lista)):
    for aux2 in range(aux,-1,-1):
        if int(lista[aux]) < int(lista[aux2]):
            entrou = 1
    if entrou == 0:
        contador += 1
    entrou = 0
print(contador)