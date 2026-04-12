N=int(input())
H=list(map(int,input().split()))
TOLL=H[0]
p=1
for i in range(1,N):
  if H[i]>=TOLL:
    p+=1
    TOLL=H[i]
print(p)