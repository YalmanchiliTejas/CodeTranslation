N=int(input())
*H,=map(int,input().split())
answer=[0]*N
for i in range(N):
  if max(H[:i+1])<=H[i]:
    answer[i]=1
print(sum(answer))