while True:
    n=int(input())
    if n==0:
        break
    
    else:
        score=[]
        for i in range(n):
            score.append(int(input()))
        score.sort()
        score.pop(0)
        score.pop(-1)
        sum=0
        for i in range(n-2):
            sum+=score[i]
        print(int(sum/(n-2)))