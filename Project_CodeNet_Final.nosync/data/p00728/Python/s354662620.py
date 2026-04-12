import math
while True:
  n=int(input())
  if n==0:
    break
  else:
    S_list=[]
    for i in range(n):
      score=int(input())
      S_list.append(score)
    S_list.remove(max(S_list))
    S_list.remove(min(S_list))
    print(math.floor(sum(S_list)/len(S_list)))
