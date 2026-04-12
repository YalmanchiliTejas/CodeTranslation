while True:
    n=int(input())

    if n==0:
        break
    a=[]
    for i in range(n):
        a=a+[int(input())]
    sum=0
    for i in range(n):
        sum+=a[i]

    score=int((sum-max(a)-min(a))/(n-2))
    print(score)