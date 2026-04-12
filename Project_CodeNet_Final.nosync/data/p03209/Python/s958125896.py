n,x = map(int,input().split())
a_list = [1]
p_list = [1]
for i in range(n):
  a_list.append(a_list[-1] * 2 + 3)
  p_list.append(p_list[-1] * 2 + 1)
def dfs(n,x):
  if x == 1:
    return 0
  if n == 1:
    if x ==2:
      return 1
    if x == 3 :
      return 2
    if x == 4 or x == 5:
      return 3
  elif 1 < x  and x <= a_list[n-1] +1:
    return dfs(n-1,x-1)
  elif x == a_list[n-1] + 2:
    return p_list[n-1] + 1
  elif a_list[n-1] + 2 < x and x <= 2 * a_list[n-1] + 2:
    return p_list[n-1] + 1 + dfs(n-1,x - (a_list[n-1] + 2))
  elif x == 2 * a_list[n-1] + 3:
    return 2 * p_list[n-1] + 1

print(dfs(n,x))
  