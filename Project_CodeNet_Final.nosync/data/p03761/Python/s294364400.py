N = input()
s = []
for i in range(N):
    s.append(raw_input())
alpha='abcdefghijklmnopqrstuvwxyz'
num = []
for i in range(26):
 num.append(0)

for j in range(26):
 num[j]=s[0].count(alpha[j])

for k in range(N-1):
 for l in range(26):
  if num[l]>0:
   aaa=s[k+1].count(alpha[l])
   if aaa<num[l]:
    num[l]=aaa
out=""
for n in range(26):
 out=out+alpha[n]*num[n]
print out