while True :
    n = int(input())
    if n == 0 :
        break
    
    magic = list([0] * n for i in range(n))
    x = (n+1)//2 - 1
    y = (n+1)//2 - 2
    for i in range(1, n**2+1) :
        x += 1
        y += 1
        while True :
            if x >= n :
                x = 0
            if y >= n :
                y = 0
            if magic[x][y] != 0 :
                x += 1
                y -= 1
                if y == -1 :
                    y = n - 1
            if x < n and y < n and magic[x][y] == 0 :
                break
        magic[x][y] = i
        
    for i in range(n) :
        for j in range(n) :
            print('{:4}'.format(magic[i][j]), end="")
        print()
            
