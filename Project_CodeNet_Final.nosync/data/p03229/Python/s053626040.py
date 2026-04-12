n=int(input())
a=sorted([int(input()) for i in range(n)])
b=[a[i] for i in range(n-1,-1,-1)]
c=[abs(a[i//2]-b[i//2]) if i%2==0 else abs(b[i//2]-a[i//2+1]) for i in range(n-1)]
c.append(abs(b[(n-1)//2]-a[0]))
d=[abs(b[i//2]-a[i//2]) if i%2==0 else abs(a[i//2]-b[i//2+1]) for i in range(n-1)]
d.append(abs(a[(n-1)//2]-b[0]))
print(max(sum(c)-min(c),sum(d)-min(d)))