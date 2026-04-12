n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
l.sort()
if n%2==0:
    ln=l[:n//2]
    lx=l[n//2:]
    print(2*(sum(lx)-sum(ln))-lx[0]+ln[-1])
else:
    ln=l[:n//2]
    lm=l[n//2]
    lx=l[n//2+1:]
    p=sum(lx)
    q=sum(ln)
    print(max(2*(p-q)+ln[-1]-lm,2*(p-q)-lx[0]+lm))