N=int(input())
M=N//2
l=[int(input()) for i in range(N)]
l.sort()
if N%2==0:
   print(-2*sum(l[0:M-1])-l[M-1]+l[M]+2*sum(l[M+1:]))
else:
   pt1=-2*sum(l[:M-1])-l[M-1]-l[M] +2*sum(l[M+1:])
   pt2=-2*sum(l[:M]) +l[M] + l[M+1] +2*sum(l[M+2:])
   print(max(pt1,pt2))