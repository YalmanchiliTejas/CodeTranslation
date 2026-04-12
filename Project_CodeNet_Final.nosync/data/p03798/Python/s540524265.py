import sys

N=int(input())
S=input()

flgT=["SSS","SWW","WWS","WSW"]
flgF=["SSW","WSS","SWS","WWW"]

if S[0]=='o':
  for i in range(4):
    str=flgT[i]
    for j in range(1,N):
      if (S[j]=="o" and str[-1]=="S") or (S[j]=="x" and str[-1]=="W"):
        str=str+str[-2]
      else:
        if str[-2]=="W":
          str=str+"S"
        else:
          str=str+"W"
    if str[-2]==str[0] and str[-1]==str[1]:
      str=str[1:-1]
      print(str)
      sys.exit()
else:
  for i in range(4):
    str=flgF[i]
    for j in range(1,N):
      if (S[j]=="o" and str[-1]=="S") or (S[j]=="x" and str[-1]=="W"):
        str=str+str[-2]
      else:
        if str[-2]=="W":
          str=str+"S"
        else:
          str=str+"W"
    if str[-2]==str[0] and str[-1]==str[1]:
      str=str[1:-1]
      print(str)
      sys.exit()

print(-1)