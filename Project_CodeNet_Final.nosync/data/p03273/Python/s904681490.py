

def provjera(listaznakova):
    x = 0
    for znak in listaznakova:
        if znak == ".":
            x = x+1
    if x == len(listaznakova):
        return False
    else:
        return True
            
    
h,w = map(int,input().split())
matrica = []
matrica_dva = []
matrica_tri = []
matrica_cet = []
matrica_rez = []
red_t = []



for x in range(h):
    red=input()
    matrica.append(red)
    
for c in matrica:
    if provjera(c):
        matrica_dva.append(c)
    else:
        h-=1
    
for x in range(w):
    for y in range(h):
        red_t.append(matrica_dva[y][x])
    matrica_tri.append(red_t)
    red_t = []

for c in matrica_tri:
    if provjera(c):
        matrica_cet.append(c)
    else:
        w-=1
red_t = []

for x in range(h):
    for y in range(w):
        red_t.append(matrica_cet[y][x])
    matrica_rez.append(red_t)
    red_t = []

for x in range(h):
    print("".join(matrica_rez[x]))