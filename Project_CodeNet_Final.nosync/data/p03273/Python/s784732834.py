h, w = [int(i) for i in input().split()]
 
s = []
for i in range(h):
  s.append(input())

set_i = set()  
set_j = set()

for i in range(h):
    for j in range(w):
      if s[i][j] =="#":
        set_i.add(i)
        set_j.add(j)
        
for i in range(h):
  answer = ""
  if i in set_i:
    for j in range(w):
      if j in set_j:
        answer += s[i][j]
    print(answer)