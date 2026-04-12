h, w = map(int, input().split())
A = []

for i in range(h):
    tmp = input()
    if(tmp != w*"."):
        A.append(tmp)

D = []

for j in range(w):
    flag = True
    for B in A:
        if(B[j] == "#"):
            flag = False
    if(flag):
        D.append(j)

for B in A:
    for j in range(w):
        if(j not in D):
            print(B[j], end="")
    print()
