n, x, m = map(int, input().split())
mod = [-1 for i in range(m)]
sum = [-1 for i in range(m)]
c = [-1 for i in range(m)]

count = 0
a = x
a_p = -1
i = 1
for i in range(1, n+1):
  
  if(mod[a] != -1):
    loop_c = c[a_p] - c[a] + 1
    loop_sum = sum[a_p] - sum[a] + a
    
    bai = (n - c[a_p])//loop_c
    nokori = (n - c[a_p])%loop_c
    
    ans = sum[a_p] + bai*loop_sum
    for j in range(nokori+1):
      ans += a
      a = mod[a]
    print(ans)
    exit()
  
  i += 1
  count += a
  sum[a] = count
  c[a] = i
  
  
    
  a_p = a
  mod[a] = (a*a)%m
  a = mod[a]
  
  
print(count)