s=input();n=len(s)
def f(i,t,k):
 if k>n-i:return 0
 a=max(t,int(s[i]));i+=1
 if a==0:z=f(i,t,k)
 elif k==1:z=a+(n-i)*9
 else: z=f(i,9,k)+(a-1)*f(i,9,k-1)+f(i,t,k-1)
 return z
print(f(0,0,int(input())))