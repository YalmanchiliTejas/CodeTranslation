def wczytaj_liste(): 
    wczytana_lista = input()
    lista_znakow = wczytana_lista.split()
    ostateczna_lista = []
    for element in lista_znakow:
        ostateczna_lista.append(int(element))
    return ostateczna_lista 

def japonska_gierka(): 
    N = wczytaj_liste()[0]
    A = wczytaj_liste()
    X = 0
    Y = 0
    wynik = [[None for i in range(N+1)] for j in range(N+1)]
    for dlugosc_kolejki in range(N+1):
        zabrano = N - dlugosc_kolejki
        for lewo in range(zabrano+1): 
            prawo = zabrano - lewo
            if dlugosc_kolejki == 0: 
                wynik[lewo][prawo] = 0 
            else:
                wynik[lewo][prawo] = max(A[lewo]-wynik[lewo+1][prawo], A[-prawo-1]-wynik[lewo][prawo+1])
    print(wynik[0][0])
    
japonska_gierka()