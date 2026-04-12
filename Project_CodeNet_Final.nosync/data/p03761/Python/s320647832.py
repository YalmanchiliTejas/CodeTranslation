from collections import defaultdict
n=int(input())

s0=list(input())
answer_dic=defaultdict(int)
for s in s0:
  answer_dic[s]+=1

for i in range(n-1):
  si=list(input())
  tmp_dic=defaultdict(int)
  for s in si:
    tmp_dic[s]+=1
    
  for s in answer_dic:
    answer_dic[s]=min(answer_dic[s],tmp_dic[s])
#print(answer_dic)

answer_list=sorted(list(answer_dic.items()))
#print(answer_list)
answer_str=[]
for c,i in answer_list:
  for ii in range(i):
    answer_str.append(c)
    
print("".join(answer_str))