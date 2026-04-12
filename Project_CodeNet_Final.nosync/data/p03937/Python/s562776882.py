from sys import stdin

nbLig,nbCol=map(int,stdin.readline().split())
grille=[]
possible=[[-1]*nbCol for i in range(nbLig)]
possible[0][0]=0
for i in range(nbLig):
    ligne=stdin.readline()
    grille.append(ligne)
compteur=0
cases=0
for lig in range(nbLig):
    for col in range(nbCol):
        if grille[lig][col]=="#" and (lig!=0 or col!=0):
            cases+=1
            maximum=-1
            if lig>0:
                maximum=max(maximum,possible[lig-1][col])
            if col>0:
                maximum=max(maximum,possible[lig][col-1])
            possible[lig][col]=maximum+1

if cases==possible[nbLig-1][nbCol-1]:
    print("Possible")
else:
    print("Impossible")