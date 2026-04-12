N=int(input())
S=list(input())
K=int(input())

No_change=S[K-1]

out=[]
for s in S:
  s_temp=s
  if s != No_change:
    s_temp='*'
  out.append(s_temp)
  
out_str=''
for o in out:
  out_str+=o
  
print(out_str)