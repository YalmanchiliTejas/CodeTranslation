cnt=0
l=[]
while 1:
    n,k=map(int,raw_input().split())
    cnt+=1
    if n==k==0:
        break
    l.append(n+k)
    if cnt%5==0:
        print chr(l.index(max(l))+65),max(l)
        l=[]