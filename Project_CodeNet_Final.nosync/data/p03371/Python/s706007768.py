A,B,C,X,Y=map(int,input().split())
ans=(10**5)*5000*2
for i in range(10**5+1):
  ans=min(i*2*C+max(0,(X-i)*A)+max(0,(Y-i)*B),ans)
print(ans)