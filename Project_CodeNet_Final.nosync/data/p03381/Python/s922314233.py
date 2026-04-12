N = int(input())
lista = list(map(int, input().split()))
newlista = sorted(lista)

lowermedian = newlista[int(len(lista)/ 2- 1)]
highermedian = newlista[int(len(lista)/2)]

for i in range(N):
  if(lista[i] <= lowermedian):
    print(highermedian)
  else:
    print(lowermedian)