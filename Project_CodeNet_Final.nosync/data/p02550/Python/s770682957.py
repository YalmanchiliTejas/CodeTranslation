N,X,M=map(int,input().split())
a=X
ls=[X]
point=N
for i in range(N):
  a=a*a%M
  if a in ls:
    point=ls.index(a)
    break
  else:
  	ls.append(a)
initial=len(ls[:point])
cycle_len=len(ls[point:])
cycle_sum=sum(ls[point:])
cycles=(N-initial)//cycle_len
cycles_rem=(N-initial)%cycle_len
print(sum(ls[:point])+cycles*cycle_sum+sum(ls[point:point+cycles_rem]))