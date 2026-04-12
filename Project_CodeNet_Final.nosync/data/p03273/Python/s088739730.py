h, w = map(int,input().split())
a_complex = []
for i in range(h):
    a_row = list(input())
    a_complex+=[a_row]

#print(a_complex)
count = 0
for i in range(h):
    if not ("#" in a_complex[i-count]):
        del a_complex[i-count]
        count += 1
#print(a_complex)
ver = []
count = 0
for i in range(w):#列
    for j in range(len(a_complex)):  #行
        ver += [a_complex[j][i-count]]
    if not ("#" in ver):
        for u in range(len(a_complex)):
            del a_complex[u][i - count]
        count+=1
    ver = []
#print(a_complex)
for i in range(len(a_complex)):
    for j in range(len(a_complex[0])):
        print(a_complex[i][j], end="")
    print("")