N = int(input())
lista = list(map(int,input().split()))
count = 0

maxindex = lista[0]
for index in lista:
    if maxindex < index:
        maxindex = index
    if index >= maxindex:
        count += 1
print(count)