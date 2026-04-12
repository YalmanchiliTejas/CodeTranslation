n = int(input())
h = list(map(int,input().split()))
height = 0
cnt = 0
for i in h:
  if height<=i:
    cnt+=1
    height = i
print(cnt)