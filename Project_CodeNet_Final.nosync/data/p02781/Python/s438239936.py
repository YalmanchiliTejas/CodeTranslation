s=input();n=len(s)
def f(i,t,k):
 if k>n-i:return 0
 a=max(t,int(s[i]));i+=1;
 return(f(i,9,k)+(a-1)*f(i,9,k-1)+f(i,t,k-1)if k-1 else a+(n-i)*9)if a else f(i,t,k)
print(f(0,0,int(input())))