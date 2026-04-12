N =input()
S =raw_input()
K =input()

tgt=S[K-1:K]

out = ""
for i in range(N):
  c=S[i]
  if c==tgt: 
    out=out+c
  else:
    out=out+'*'

print out