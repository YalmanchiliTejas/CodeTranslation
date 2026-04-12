while 1:
    n=int(input())
    if n==0:break
    score=[]
    for i in range(n):
        score.append(int(input()))
    score.sort()
    score=score[1:-1]
    print(sum(score)//len(score))
