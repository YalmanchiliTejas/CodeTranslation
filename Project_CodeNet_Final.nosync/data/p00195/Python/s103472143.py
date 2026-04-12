S = ["A","B","C","D","E"]
while True:
    L = []
    a,p = map(int,input().split())
    if a == 0:
        break
    L.append(a+p)
    for i in range(4):
        a,p = map(int,input().split())
        L.append(a+p)
    m = max(L)
    s = L.index(m)
    print(S[s],m)
