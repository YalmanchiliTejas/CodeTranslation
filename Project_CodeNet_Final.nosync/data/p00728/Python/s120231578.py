while True:
    n = int(input())
    if n == 0:
        break
    
    s = []
    for i in range(n):
        s.append(int(input()))

    s.sort()
    s.pop(0)
    s.pop()
    
    print(int(sum(s)/len(s)))
