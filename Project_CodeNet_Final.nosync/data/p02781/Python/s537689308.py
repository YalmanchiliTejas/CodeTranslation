s=input()*2;n=len(s)/2
def f(i,t,k):
 if k>n-i:return 0
 a=max(t,int(s[i]));i+=1;
 if t:return f(i,9,k)+a*f(i,9,k-1)if k else 1
 else:return(f(i,9,k)+(a-1)*f(i,9,k-1)+f(i,0,k-1)if k else 1)if a else f(i,0,k)
print(f(0,0,int(input())))