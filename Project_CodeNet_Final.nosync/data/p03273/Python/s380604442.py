h,w = map(int,input().split())
A = [input() for i in range(h)]
AnsH=[]
for i in range(h):
    if "#" in A[i]:
        AnsH.append(i)
AnsW=[]
for i in range(w):
    c = 0
    for j in range(h):
        if A[j][i]=="#":
            c = 1
    if c == 1:
        AnsW.append(i)
for i in AnsH:
    for j in AnsW:
        print(A[i][j],end="")

    print()