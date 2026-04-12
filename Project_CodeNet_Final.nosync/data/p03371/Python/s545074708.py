A,B,C,X,Y=[int(x) for x in input().rstrip().split()]
ans=float('inf')
for i in range(10**5+1):
  now=2*C*i+max(0,X-i)*A+max(0,Y-i)*B
  ans=min(ans,now)
print(ans)