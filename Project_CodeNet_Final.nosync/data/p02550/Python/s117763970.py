N, X, M = map(int, input().split())

now = X
used = [X]
i = 1
T = True
while T:
  if i == N:
    print(sum(used))
    quit()
  else:
    next_ = (now * now) % M
    if next_ in used:
      T = False
    else:
      used.append(next_)
      now = next_
    i += 1  

count = used.index(next_)
ans = sum(used[:count])
#print(ans)
roop = len(used) - count
roop_ans = sum(used[count:])
#print(roop, roop_ans)
index = (N - count) % roop
#print(index)
ans += roop_ans * int((N - count) // roop)
#print(ans)
#if index == 0:
#  index = roop
  
ans += sum(used[count:count + index]) 
  
print(ans)
#print(used)    
