n = input()
l = list(input().split())
 
cnt = 0
max_height = 0
for i in range(len(l)):
  if int(l[i]) >= int(max_height):
    cnt +=1
    max_height = l[i]
    
print(cnt)   