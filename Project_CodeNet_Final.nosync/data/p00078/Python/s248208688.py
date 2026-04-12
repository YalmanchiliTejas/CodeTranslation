def fill(x,y,count):
    global board
    if count == n**2:
        return 0
    count += 1
    while board[x%n][y%n] != 0:
        x += 1
        y -= 1
    board[x%n][y%n] = count
    fill(x+1,y+1,count)

    
while(1):
    n = int(input())
    if n == 0:
        break
    board = [[0 for i in range(n)] for j in range(n)]
    fill(int(n/2)+1,int(n/2),0)
    board = [["{: >4}".format(i) for i in j] for j in board]
    [print(*board[i],sep="") for i in range(n)]  
