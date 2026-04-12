while True:
    n=int(input())
    s=[]
    if n==0:
        break
    else:
        for i in range(n):
            s.append(int(input()))
        s.sort()
        del(s[0])
        del(s[-1])
        
        print(f'{sum(s)//(n-2)}')
