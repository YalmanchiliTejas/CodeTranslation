n =int(input())
h = [int(x) for x in input().split()]
cnt =1

for i in range(1,len(h)):
  if h[i] ==max(h[:i+1]):
    cnt +=1
print(cnt)