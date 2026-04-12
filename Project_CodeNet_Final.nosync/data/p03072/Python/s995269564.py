#maior que todos os anteriores
k = int(input())
numerosStr = input().split()
numeros=[]
certo = True
contador=1
for q in numerosStr:
    numeros.append(int(q))

for i in range(1,len(numeros)):
    certo = True
    for j in range(i):
        if numeros[i] < numeros[j]:
            certo=False
            break
    if certo:
        contador+=1
print(contador)