import sys

while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break
    
    score = []
    for i in xrange(n):
        x = int(sys.stdin.readline())
        
        score.append(x)
    score.sort()
    result = score[1:-1]
    print sum(result) / len(result)