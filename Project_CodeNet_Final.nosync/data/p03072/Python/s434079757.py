H =  input()
a = list(map(int,input().split()))
counter =0
for i, n in enumerate(a):
  if i ==0:
    counter +=1
  elif i!=0 and max(a[:i])<=n:
    counter +=1
print (counter)