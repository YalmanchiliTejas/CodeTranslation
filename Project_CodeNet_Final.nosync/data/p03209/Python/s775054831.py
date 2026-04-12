M = list(map(int,input().split()))
N = M[0]
X = M[1]

number = 0

while not X == 0:
    for x in range(N,-1,-1):
        if 2**(x+2)-3 <= X-N+x:
            number = number + 2**(x+1) -1 
            X = X-N+x-2**(x+2)+3
            N = x
            if X >= 1:
                X = X-1 
                number = number + 1
                break
            else:
                break
        if x == 0:
            X = 0 
            break
else:
    print(number)