while True:
    n = int(input())
    if n == 0: break
    
    l=[]
    for _ in range(n):
        l.append(int(input()))
    l.sort()
    print(sum(l[1:-1])//(n-2))