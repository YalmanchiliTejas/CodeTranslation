N,X=map(int,input().split())
PILE=[2**(i+2)-3 for i in range(51)]
def dp(n,x):#レベルnバーガーのx層目まで
   if x==0:
       return 0
   if n==0 and x==1:
       return 1
   if n>=1:
       bp=PILE[n-1]
       if x==1:
           return 0
       elif x<=1+bp:
           return dp(n-1,x-1)
       elif x==2+bp:
           return 1+dp(n-1,bp)
       elif 2+bp<x<=2+2*bp:
           return 1+dp(n-1,bp)+dp(n-1,x-2-bp)
       elif x==3+2*bp:
           return 1+dp(n-1,bp)*2

print(dp(N,X))