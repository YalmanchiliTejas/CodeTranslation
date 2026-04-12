h, w = map(int, input().split())
a = []
for i in range(h):
    A = list(map(str,input().split()))
    a.append(A)
kesu = []
for i in range(h):
    b = str(a[i])
    ten = 0
    for l in range(w):
        if b[l+2] == ".":
           ten += 1
    if w == ten :
        kesu.append(i)
for i in range(len(kesu)):
    K = int(kesu[i])
    a.pop(K-i)
hi = []
for i in range(w):
    hkari = ""
    for l in range(len(a)):
        h = str(a[l])
        hz = str(h[i+2])
        hkari += str(hz)
    hi.append(hkari)
kesu = []
for i in range(len(hi)):
    b = str(hi[i])
    ten = 0
    for l in range(len(b)):
        if b[l] == ".":
            ten += 1
    if len(b) == ten:
        kesu.append(i)
for i in range(len(kesu)):
    K = int(kesu[i])
    hi.pop(K-i)
b = len(str(hi[0]))
ans = []
for i in range(b):
    hkari = ""
    for l in range(len(hi)):
        h = str(hi[l])
        hz = str(h[i])
        hkari += str(hz)
    ans.append(hkari)
for i  in range(len(ans)):
    print(ans[i])