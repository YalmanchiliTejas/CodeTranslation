def main():
  n=int(input())
  h = list(map(int,input().split()))
  ans=0
  for i in range(0,n):
    flg=0
    for j in range(0,i):
      if h[i]<h[j]:
        flg=1
        break
    if flg==0:
      ans+=1
  print(ans)
main()