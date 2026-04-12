while True:
    n=int(input())
    if n==0:
        break
    a=[]
    for i in range(n):
        a.append(int(input()))
    print((sum(a)-max(a)-min(a))//(len(a)-2))
