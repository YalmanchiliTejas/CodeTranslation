while True:
    n = int(input())
    a = []
    if n == 0:
        break
    for i in range(n):
        a.append(int(input()))
    print((sum(a)-max(a)-min(a))//(len(a)-2))
        

