HW = input()
masu = "none"
hw = HW.split()

Adata = []
for lop in range(int(hw[0])):
    A = input()
    Adata.append(A)

x = []
y = []
buf = ""
for lop in range(int(hw[0])):
    if str(Adata[lop]).find("#") == -1:
      x.append(lop)
      
for lop in range(int(hw[1])):
    for lop2 in range(int(hw[0])):
        buf = buf + str(Adata[lop2][lop])
    if str(buf).find("#") == -1:
        y.append(lop)
    buf = ""

for lop in range(len(x)-1,-1,-1):
    Adata.pop(x[lop])


ans = []
for lop in range(len(Adata)):
    buf = list(Adata[lop])
    for lop2 in range(len(y)-1,-1,-1):
        buf.pop(y[lop2])
    ans.append(buf)

for lop in range(len(ans)):
    ANS = ""
    for lop2 in range(len(ans[0])):
        ANS += ans[lop][lop2]
    print(ANS)
