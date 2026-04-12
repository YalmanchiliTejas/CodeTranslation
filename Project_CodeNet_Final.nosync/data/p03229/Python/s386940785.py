n=int(input())
l=sorted([int(input())for i in range(n)],reverse=1)
if n%2:
    print(max(2*sum(l[:n//2-1])+l[n//2-1]+l[n//2]-2*sum(l[n//2+1:]),2*sum(l[:n//2])-sum(l[n//2:n//2+2])-2*sum(l[n//2+2:])))
else:
    o=-1
    print(2*sum(l[:n//2-1])+l[n//2+o]-l[n//2+1+o]-2*sum(l[o+n//2+2:]))