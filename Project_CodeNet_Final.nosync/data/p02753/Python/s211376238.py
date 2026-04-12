S = input()
dict_st = {'A':0, 'B':0}
for i in S:
  dict_st[i]+=1

for k,v in dict_st.items():
  if v<=2 and v>0:
    print('Yes')
    break
  elif v>2:
    print('No')
    break