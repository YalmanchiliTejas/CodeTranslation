A,B=list(map(int,input().split()))
n_l=[[] for i in range(A)]
from collections import deque
import itertools
for i in range(B):
   N,M= list(map( int,input().split()))
   n_l[N-1].append(M)
   n_l[M-1].append(N)
all_l=list(range(2,A+1))
first_list=[]
for i in n_l[0]:
   all_l_n=all_l.copy()
   for v in itertools.permutations(all_l_n):
      first_list.append(v)
ans=0
first_list=list(set(first_list))
for x in first_list:
   if x[0] in n_l[0]:
      s=1
      for k in range(len(x)-1):
         if x[k+1] in n_l[x[k]-1]:
            pass
         else:
            s=0
            break
      if s == 1:
         ans+=1
print(ans)