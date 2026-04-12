def f(s,i,t,k):
 n=len(s)
 if k>n-i:return 0
 a=max(t,int(s[i]))
 z=0
 i+=1
 if a==0:z=f(s,i,t,k)
 elif k==1:z=a+(n-i)*9
 else:
  z+=f(s,i,9,k)
  z+=(a-1)*f(s,i,9,k-1)
  z+=f(s,i,t,k-1)
 return z
print(f(input(),0,0,int(input())))