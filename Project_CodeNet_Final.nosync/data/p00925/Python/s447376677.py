s,ans=input(),int(input())
x=int(s[0])
for i in range(1,len(s),2):
  y=int(s[i+1])
  x=x*y if s[i]=='*' else x+y
print("IMLU"[int(eval(s)==ans)+(int(x==ans)<<1)])