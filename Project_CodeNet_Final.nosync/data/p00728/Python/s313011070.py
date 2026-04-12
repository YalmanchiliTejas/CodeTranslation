import math
while True:
    score = []
    n = int(input())
    if n == 0:
        break
    else:
        for i in range(n):
            score.append(int(input()))
    
    score.remove(min(score))
    score.remove(max(score))
    
    print(math.floor(sum(score)/len(score)))
