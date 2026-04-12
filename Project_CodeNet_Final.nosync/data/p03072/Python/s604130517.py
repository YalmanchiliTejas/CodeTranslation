N = int(input())
h_list = list(map(int, input().split()))

hh = [h_list[0]]
ans = 1
for index, i in enumerate(h_list):
  if index == 0:
    continue;
  else:
    if i >= max(hh):
      ans+=1
  hh.append(i)
  
print(ans)