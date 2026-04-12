N=int(input())
S=[input() for i in range(N)]
ans=[]
for i in range(27):
  A=[]
  for j in S:
    A.append(j.count(chr(97+i)))
  ans.append(chr(97+i)*(min(A)))
print(*ans,sep='')