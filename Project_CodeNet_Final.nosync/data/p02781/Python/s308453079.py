def f(s,t,k):
 n=len(s)
 if k>n: return 0
 a=max(t,int(s[0]))
 z=0
 if a==0:z=f(s[1:],t,k)
 elif k==1:z=a+(n-1)*9
 else:
  if k-1<=n:z+=f(s[1:],9,k)
  z+=(a-1)*f(s[1:],9,k-1)
  z+=f(s[1:],t,k-1)
 return z
print(f(input(),0,int(input())))
