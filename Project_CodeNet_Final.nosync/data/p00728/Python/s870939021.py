while True:
    n = int(input())
    if n == 0:
        break
    lista = []
    for i in range(n):
        lista.append(int(input()))
    lista.sort()
    lista.pop(0)
    lista.pop(-1)
    ave = sum(lista)//(n-2)
    print(ave)

