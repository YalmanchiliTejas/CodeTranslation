N = int(input())
mt = list(map(int,input().split()))
cnt = 1
max_h = mt[0]
for i in range(1,N):
  if mt[i]-max_h>=0:
    max_h = mt[i]
    cnt+=1
print(cnt)