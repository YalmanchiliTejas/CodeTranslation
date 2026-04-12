N=int(input());
X=list(map(int,input().split()))
s=0;t=0;
for i in range(N):
  s+=X[i];
  t+=X[i]*X[i];
print(((s*s-t)//2)%1000000007)