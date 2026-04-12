n=int(input())
l0=[0]*n
l=[l0[:] for _ in range(26)]
for i in range(n):
  a=input()
  for x in a:
    if x=='a':
      l[0][i]+=1
    elif x=='b':
      l[1][i]+=1
    elif x=='c':
      l[2][i]+=1
    elif x=='d':
      l[3][i]+=1
    elif x=='e':
      l[4][i]+=1
    elif x=='f':
      l[5][i]+=1
    elif x=='g':
      l[6][i]+=1
    elif x=='h':
      l[7][i]+=1
    elif x=='i':
      l[8][i]+=1
    elif x=='j':
      l[9][i]+=1
    elif x=='k':
      l[10][i]+=1
    elif x=='l':
      l[11][i]+=1
    elif x=='m':
      l[12][i]+=1
    elif x=='n':
      l[13][i]+=1
    elif x=='o':
      l[14][i]+=1
    elif x=='p':
      l[15][i]+=1
    elif x=='q':
      l[16][i]+=1
    elif x=='r':
      l[17][i]+=1
    elif x=='s':
      l[18][i]+=1
    elif x=='t':
      l[19][i]+=1
    elif x=='u':
      l[20][i]+=1
    elif x=='v':
      l[21][i]+=1
    elif x=='w':
      l[22][i]+=1
    elif x=='x':
      l[23][i]+=1
    elif x=='y':
      l[24][i]+=1
    elif x=='z':
      l[25][i]+=1
b=0
s=''
for x in l:
  c=min(x)
  if b==0:
    s+='a'*c
  elif b==1:
    s+='b'*c
  elif b==2:
    s+='c'*c
  elif b==3:
    s+='d'*c
  elif b==4:
    s+='e'*c
  elif b==5:
    s+='f'*c
  elif b==6:
    s+='g'*c
  elif b==7:
    s+='h'*c
  elif b==8:
    s+='i'*c
  elif b==9:
    s+='j'*c
  elif b==10:
    s+='k'*c
  elif b==11:
    s+='l'*c
  elif b==12:
    s+='m'*c
  elif b==13:
    s+='n'*c
  elif b==14:
    s+='o'*c
  elif b==15:
    s+='p'*c
  elif b==16:
    s+='q'*c
  elif b==17:
    s+='r'*c
  elif b==18:
    s+='s'*c
  elif b==19:
    s+='t'*c
  elif b==20:
    s+='u'*c
  elif b==21:
    s+='v'*c
  elif b==22:
    s+='w'*c
  elif b==23:
    s+='x'*c
  elif b==24:
    s+='y'*c
  elif b==25:
    s+='z'*c
  b+=1
print(s)