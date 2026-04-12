N = int(input())
H = list(map(int,input().split()))

cnt = 0
for idx,h in enumerate(H):
  if h == max(H[:idx+1]):
    cnt +=1

print(cnt)