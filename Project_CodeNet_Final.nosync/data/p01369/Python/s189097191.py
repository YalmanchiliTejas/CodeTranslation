migi="yuiophjklnm"
hidari="qwertasdfgzxcvb"
while True:
  n=input()
  if n=="#":
    break
  count=0
  for i in range(len(n)):
    if i==0:
      if n[i] in migi:
        flag=1
      else:
        flag=0
    if i>=1:
      if n[i] in migi and flag==0:
        flag=1
        count+=1
      if n[i] in hidari and flag==1:
        flag=0
        count+=1
    #print(flag)
  print(count)
