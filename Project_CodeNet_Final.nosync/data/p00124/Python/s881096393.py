f = True
while True:
    n = int(input())
    if n == 0:
        break
    T = []
    for i in range(n):
        name,w,l,d = list(input().split())
        T.append((name,i,int(w)*3+int(d)))
    if f: f = False
    else: print()
    for i in sorted(T, key = lambda x:(-x[2],x[1])):
        print(i[0],",",i[2],sep="")
