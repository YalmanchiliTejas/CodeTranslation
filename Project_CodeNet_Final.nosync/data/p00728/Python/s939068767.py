while True:
    n=int(input())
    if n==0:
        break
    else:
        score=[0]*n
    for i in range(n):
        score[i]=int(input())
    max=score[0]
    min=score[0]
    for i in range(1,n):
        if max<score[i]:
            max=score[i]
        if min>score[i]:
            min=score[i]
    print(int((sum(score)-max-min)/(n-2)))
