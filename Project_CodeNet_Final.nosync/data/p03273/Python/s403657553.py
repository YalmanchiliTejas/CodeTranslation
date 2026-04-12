h,w = map(int, input().split())
Hli,Wli = [0 for _ in range(h)],[0 for _ in range(w)]
A = []
for i in range(h):
    l = input()
    for j in range(w):
        if l[j] == "#":
            Hli[i] = 1
            Wli[j] = 1
    A.append(l)
# print(Hli,Wli)
for i in range(h):
    str = ""
    for j in range(w):
        if Hli[i]*Wli[j] == 1:
            str += A[i][j]
    if str != "": print(str)