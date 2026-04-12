import math
def main():
  h,w = list(map(int,input().split()))
  a = [input() for i in range(h)]
  ans=0
  i=0
  while i<h:
    if '#' not in a[i] :
      a.pop(i)
      h=h-1
      i-=1
    i+=1
  i=0
  while i<w:
    for j in range(0,h):
      if a[j][i]=='#':
        break
      elif j==h-1:
        for k in range(0,h):
          a[k]=a[k][:i]+a[k][i+1:]
        w-=1
        i-=1
    i+=1
  for i in range(0,h):
    print(a[i])
main()