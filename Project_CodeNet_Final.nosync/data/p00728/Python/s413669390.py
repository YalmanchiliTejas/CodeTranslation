while True:
    n=int(input())
    min=1000
    max=0
    sum=0
    if n==0:
        break
    for i in range(n):
        tennsuu=int(input())
        sum+=tennsuu
        if tennsuu<min:
            min=tennsuu
        if tennsuu>max:
            max=tennsuu
    print((sum-min-max)//(n-2))
