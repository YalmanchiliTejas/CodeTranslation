while True:
    n = int(input())
    if n > 0:
        l = []
        for i in range(n):
            s = int(input())
        
            l.append(s)
        l.remove(max(l))
        l.remove(min(l))
        x = sum(l)
        y = len(l)
        print(int(x/y))
    if n == 0:
        break
