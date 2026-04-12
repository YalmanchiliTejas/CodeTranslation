N = int(input())
Heights = map(int, input().split())

cnt=0
Temp=[]
for i in Heights:
  Temp.append(i)
  if all([x<=i for x in Temp]):
    cnt += 1

print(cnt)