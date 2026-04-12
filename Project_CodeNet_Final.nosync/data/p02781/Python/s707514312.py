import math
n=input()
k=int(input())
t=0
def com(a,b):
    if b>a:
        return 0
    else:
        return math.factorial(a)//(math.factorial(b)*math.factorial(a-b))
def su(n,k,i,s):
    if s==0:
        return 1
    if len(n)-i<s:
        return 0
    if n[i]=="0":
        return su(n,k,i+1,s)
    else:
        return (9**s)*(com(len(n)-i-1,s))+(int(n[i])-1)*(9**(s-1))*(com(len(n)-i-1,s-1))+su(n,k,i+1,s-1)
print(su(n,k,0,k))