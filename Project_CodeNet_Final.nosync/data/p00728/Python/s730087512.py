while True:
    n = int(input())
    if n == 0:
        break
    else :
        lista = [0]*n
        for i in range (n):
            lista[i] = int(input())
        lista.remove(max(lista))
        lista.remove(min(lista))
        print(sum(lista)//len(lista))
