import math
while True:
    n = int(input())
    scores = [int(input()) for i in range(n)]
    scores.sort()
    
    if n == 0:
        break
    total = 0
    
    for i in range(1, n - 1):
        total += scores[i]
        
    print(math.floor(total / (n - 2)))
