n=int(input())
k=int(input())
def main(N,K):
  ans=0
  if N<=100+10**6:
    for i in range(1,N+1):
      a=str(i)
      if len(a)-list(a).count("0")==K:
        ans+=1
    return ans
  L=list(map(int,list(str(N))))
  ans=0
  L=list(map(int,list(str(N))))
  if K==1:#おけ
    return (len(str(N))-1)*9+int(str(N)[0])
  elif K==2:#おけ
    for i in range(len(L)-1):
      ans+=(9*(int(str(N)[0])-1))
      for j in range(i+1,len(L)):
        if i==0:
          if j==1:
            ans+=int(str(N)[1])
          else:
            ans+=9
        else:
          ans+=81
    return ans
  else:
    le=len(L)
    for i in range(le-2):
      for j in range(i+1,le-1):
        for k in range(j+1,le):
          if i==0:
            ans+=81*(int(str(N)[0])-1)
            if j==1:
              ans+=9*(int(str(N)[1])-1)
              if k==2:
                ans+=int(str(N)[2])
              else:
                ans+=9
            else:
              ans+=81
          else:
            ans+=729
    return ans
ans2=0
L=list(str(n))
a=len(L)
for i in range(a):
  L=list(str(n))
  s=L[:a-i-1]
  t=L[a-i-1:]
  t=int("".join(t))
  p=s.count("0")
  p=len(s)-p
  if p>k:
    n-=t+1
  elif p==k:
    n-=t+1
    ans2+=1
  else:
    ans2+=main(t,k-p)
    n-=t+1
print(ans2)