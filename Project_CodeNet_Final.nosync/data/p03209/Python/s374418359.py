n,x=map(int,input().split())

atusa=[1]
Pkosu=[1]
for i in range(n):
  atusa.append(atusa[-1]*2+3)
  Pkosu.append(Pkosu[-1]*2+1)

def getPkosu(level,num):
  #print(level,num)
  if level==0 and num==0:
    return 0
  elif level==0 and num==1:
    return 1
  elif num==1 or num==0:
    return 0
  elif num <= atusa[level-1]+1:
    return getPkosu(level-1,num-1)
  elif num == atusa[level-1]+2:
    return Pkosu[level-1]+1
  elif num <= atusa[level-1]*2+2:
    return Pkosu[level-1]+getPkosu(level-1,num-(2+atusa[level-1]))+1
  else:
    return Pkosu[level-1]*2+1

print(getPkosu(n,x))
#print(atusa)
#print(Pkosu)
