n=input()
l=len(n)
k=int(input())
def f(n,k):
  l=len(n)
  if l<k:return 0
  if n[0]=="0":return f(n[1:],k)
  if k==1:
    ans=((l-1)*9)+int(n[0])
  if k==2:
    ans=((l-1)*(l-2)//2)*81+(int(n[0])-1)*((l-1)*9)
    ans+=f(n[1:],k-1)
  if k==3:
    ans=(int(n[0])-1)*((l-1)*(l-2)//2)*81+((l-1)*(l-2)*(l-3)//6)*9*9*9
    ans+=f(n[1:],k-1)
  return ans
print(f(n,k))