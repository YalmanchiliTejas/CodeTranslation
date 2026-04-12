for i in range(20):
    n = int(input())
    
    if n == 0:
        break
    
    data = list()
    for j in range(n):
        a = int(input())
        data.extend([a])
    #print(data)
    
    x = sum(data) - min(data) - max(data)
    #print(x)
    print(x // (n-2) )
