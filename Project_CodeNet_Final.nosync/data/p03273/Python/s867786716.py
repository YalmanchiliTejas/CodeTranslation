H,W = map(int,input().split())
L = []


for _ in range(H):
    s=input()
    l=[]
    for x in s:
        l.append(x)
    for x in l:
        if x == ".":
            pass
        else:
            L.append(l)
            break
delete=[]
cou=0
for i in range(W):
    cnt = 0
    for j in range(len(L)):
        if L[j][i]  == '.':
            cnt += 1
        else:
            cnt = 0
    if cnt == len(L):
        delete.append(i-cou)
        cou+=1
for i in delete:
    for j in range(len(L)):
        del L[j][i]

for x in L:
    for y in x:
        print(y,end="")
    print()
