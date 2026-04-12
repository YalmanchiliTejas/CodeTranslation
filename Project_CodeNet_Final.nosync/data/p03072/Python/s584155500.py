N=int(input())
H=list(map(int,input().split()))
cnt=1
h=H[0]
for i in range(1,N):
  if h<=H[i]:
    cnt+=1
    h=max(H[i],h)
print(cnt)  