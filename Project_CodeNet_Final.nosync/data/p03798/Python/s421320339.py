N = int(input())
s = input()

# 最初の2人を決めると全部決まっていく

def make_arr(first,second):
  result = [first,second]
  last,prev = second,first
  for ox in s[1:] + s[0]:
    if (ox == 'o') ^ (last == 0):
      # 両隣が異なる
      last,prev = 1-prev,last
    else:
      # 両隣が一致
      last,prev = prev,last
    result.append(last)
    continue
  bl = (result[0] == result[-2]) and (result[1] == result[-1])
  return bl,result[:-2]


answer = '-1'
for fi,se in [[0,0],[0,1],[1,0],[1,1]]:
  bl,li = make_arr(fi,se)
  if bl:
    answer = ''.join(['W' if x else 'S' for x in li])
print(answer)