N=int(input())
H=list(map(int,input().split()))
cnt=1
for i in range(1,N):
  list_i=H[0:i+1]
  if max(list_i)==H[i]:
    cnt+=1
print(cnt)