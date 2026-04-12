def wczytaj_liste(): 
    wczytana_lista = input()
    lista_znakow = wczytana_lista.split()
    ostateczna_lista = []
    for element in lista_znakow:
        ostateczna_lista.append(int(element))
    return ostateczna_lista 

def AC_WC():
    N, M = wczytaj_liste()
    if N == M: 
        print('Yes')
    else: 
        print('No')
        
AC_WC()