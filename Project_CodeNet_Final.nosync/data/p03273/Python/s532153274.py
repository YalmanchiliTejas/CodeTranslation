import copy

H,W = map(int,input().split())
a = []
for i in range(H):
    a.append(input().split())
aa = copy.copy(a)
#print(a)
aaa = 0
d = ""
for i in range(W):
    d += "."
for i in range(H):
    if a[i][0] == d:
        aa.pop(i-aaa)
        aaa += 1
#print(aa)
b = []
bb = ""
for i in range(W):
    for j in range(H-aaa):
        bb += aa[j][0][i]
    b.append(bb)
    bb = ""
#print(b)
d = ""
for i in range(H-aaa):
    d += "."
#print(d)
bc = copy.copy(b)
bbb = 0
for i in range(W):
    if b[i] == d:
        bc.pop(i-bbb)
        bbb += 1
#print(bc)
ans = []
ansc = ""
for i in range(H-aaa):
    for j in range(W-bbb):
        ansc += bc[j][i]
    ans.append(ansc)
    ansc = ""
#print(ans)
for i in range(H-aaa):
    print(ans[i])