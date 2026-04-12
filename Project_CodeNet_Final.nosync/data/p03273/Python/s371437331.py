a,b = list(map(int,input().split()))
A = []
AAA = 0
list = [["" for i in range(b)] for j in range(a)]
for i in range(a):
    n = input()
    if n.count(".") == b:
       pass 
    else:
        for j in range(b):
            list[i][j] = n[j]
for i in range(b):
    for j in range(a):
        A.append(list[j][i])
    if len(A) == A.count(".")+A.count(""):
        for k in range(a):
            list[k][i] = ""
    A = []
for i in range(a):
    for j in range(b):
        if list[i][j] != "":
            print(list[i][j],end="")
            AAA = 1
    if AAA == 1:
        print()
    AAA = 0