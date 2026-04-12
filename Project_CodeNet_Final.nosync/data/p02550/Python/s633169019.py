N,X,M=map(int,input().split())

term_set={X}
term_list=[X]
for i in range(1,N):
  term1=term_list[-1]
  term2=term1**2%M
  term_list.append(term2)
  if term2 in term_set:
    break
  else:
    term_set.add(term2)
#print(term_list)
#print(len(term_list))

if len(term_list)==N:
  print(sum(term_list))
else:
  c2=len(term_list)-1
  c1=term_list.index(term_list[-1])
  #print(c1,c2)
  
  answer=sum(term_list[:c1])
  sum_cycle=sum(term_list[c1:c2])
  
  num_cycle=(N-c1)//(c2-c1)
  rem_cycle=(N-c1)%(c2-c1)
  answer+=sum_cycle*num_cycle
  answer+=sum(term_list[c1:c1+rem_cycle])
  print(answer) 