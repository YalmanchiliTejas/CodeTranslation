n=int(input())
h=list(map(int,input().split()))
i=0
j=0
ans=0
while True:
  try:
     if h[i]>=j:
        ans=ans+1
        j=h[i]
     i=i+1
  except:
       print(ans)
       break