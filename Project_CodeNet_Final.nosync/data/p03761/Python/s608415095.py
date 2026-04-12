n = int(input())
s = []

for i in range(n):
  s.append(input())
  
#共通して出てくる文字を見つける 
temp_set = {}
for i in range(n):
  if i == 0:
    temp_set = set(list(s[i]))
  else:
    temp_set = temp_set.intersection(s[i])

    
#各文字について、各文字列に出てくる最小回数を探す
counter_moji = []
for _, moji in enumerate(temp_set):
  num_count = 500
  for i in range(len(s)):
    current_count = s[i].count(moji)
    if num_count > current_count:
      num_count = current_count
  counter_moji.append(num_count)
  
ans = []
for i, moji in enumerate(temp_set):
  for _ in range(counter_moji[i]):
    ans.append(moji)   

ans.sort()
print("".join(ans))
