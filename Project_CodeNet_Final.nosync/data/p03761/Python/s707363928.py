n=int(input())
s=[]
# アルファベット(a〜z)→数値(1〜26)小文字限定
a2n = lambda c: ord(c) - ord('a') + 1
# 数値(1〜26)→アルファベット(a〜z)
n2a = lambda c: chr(c+64).lower()

for _ in range(n):
  s_=input()
  si=[]
  for i in range(1,27):
    si.append(s_.count(n2a(i)))
  s.append(si)
ans=''
#print(s)
for i in range(26):
  a=min([s[j][i] for j in range(len(s))])
  #print(str(a)+' '+n2a(a))
  ans+=n2a(i+1)*a
  
print(ans)


