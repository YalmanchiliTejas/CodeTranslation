l=set()
s={}
while 1:
    n,k=map(int,raw_input().split(','))
    if n==k==0:
        break
    l.add(k)
    s[n]=k
l2=sorted(list(l))[::-1]
while 1:
    try:
        n=int(raw_input())
        print l2.index(s[n])+1
    except:
        break