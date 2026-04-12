while True:
    a=0
    ma=0
    mi=99999
    n = int(input())
    if n == 0:
        break
    else:
        for i in range(n):
            b=int(input())
            a=a+b
            if ma<b:
                ma=b
            if mi>b:
                mi=b
        answer=(a-ma-mi)//(n-2)
        print(answer)
