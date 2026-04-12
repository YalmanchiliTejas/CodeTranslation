while True:
    n = int(input())
    if n==0: break
    score=[int(input()) for _ in range(n)]
    score.sort()
    score.pop(-1)
    score.pop(0)
    s=sum(score)
    n=len(score)
    mean=s/n
    print(int(mean))
