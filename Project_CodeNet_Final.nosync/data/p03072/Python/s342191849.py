N = int(input())
H = list(map(int,input().split()))
m = 0
c = 0
 
for h in H:
  if m <= h:
    #見れる
    c = c + 1
    m = h
print(c)