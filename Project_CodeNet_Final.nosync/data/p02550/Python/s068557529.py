import sys
n,x,m = map(int,input().split())

lst_sum = [0,x]
loop = [0]*(10**5)
loop[x] = 1
s = 1
for i in range(2,n+1):
  y = ((lst_sum[-1] - lst_sum[-2])**2)%m
                          
  if loop[y] != 0:
    l = i-loop[y]
    d = (n-loop[y]+1) // l
    q = (n-loop[y]+1) % l
    sum_loop = lst_sum[-1]-lst_sum[loop[y]-1]
    sum_first = lst_sum[loop[y]-1]
    if q == 0:
      sum_rest = 0
    else:
      sum_rest = lst_sum[loop[y] + q-1] - lst_sum[loop[y]-1]
    print(sum_first+d*sum_loop+sum_rest)
    sys.exit()      
  else:
    s += 1
    loop[y] = s
    lst_sum.append(lst_sum[-1] + y)
    
print(lst_sum[-1])    

    
    
    
  


