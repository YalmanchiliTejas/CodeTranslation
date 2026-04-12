n = int(input())
s = input()
k = int(input())
sl = list(s)
for i in range(n):
   if sl[i]!=s[k-1]:
      sl[i]='!'
sc= "".join(sl)
print(sc.replace('!', '*'))