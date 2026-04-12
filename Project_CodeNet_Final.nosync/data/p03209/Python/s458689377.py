n, x = [int(item) for item in input().split()]

p_num = []
pb_num = []
for i in range(n+1):
  if i == 0:
    p_num.append(1)
    pb_num.append(1)
  else:  
    p_num.append(p_num[-1] * 2 + 1)
    pb_num.append(pb_num[-1] * 2 + 3)
    
def get_p_num(n, x):
  if n == 0 and x == 1:
    return 1
  
  if x == 1:
    return 0
  elif x < (pb_num[n] + 1)//2:
    return get_p_num(n-1, x-1)
  elif x == (pb_num[n] + 1)//2:
    return p_num[n-1] + 1
  elif x < pb_num[n]:
    return p_num[n-1] + 1 + get_p_num(n-1, x - pb_num[n-1] - 2)
  else:
    return p_num[n-1] * 2 + 1
                 
print(get_p_num(n, x))
