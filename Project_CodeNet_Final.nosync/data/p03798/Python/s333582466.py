N=int(input())
s=input()
ans=[""]*4
#まず先頭が羊で、右が羊の時を考える
flag=0
animals=[""]*N
animals[0]="S"
if s[0] == "o":
    animals[N-1]="S"
    animals[1]="S"
else:
    animals[N-1]="W"
    animals[1]="S"
#print(animals)
for i in range(1,N-2):
    if animals[i]=="S":
        if s[i]=="o":
            animals[i+1]=animals[i-1]
        else:
            if animals[i-1]=="S":
                animals[i + 1] ="W"
            else:
                animals[i + 1] = "S"
    else:
        if s[i]=="x":
            animals[i + 1] = animals[i - 1]
        else:
            if animals[i-1]=="S":
                animals[i + 1] ="W"
            else:
                animals[i + 1] = "S"
    #print(animals)
if (animals[N-2]=="W"):
    if (animals[N-3]!=animals[N-1])and(s[N-2]=="o"):
        flag=flag+1
    elif (animals[N-3]==animals[N-1])and(s[N-2]=="x"):
        flag=flag+1
else:
    if (animals[N-3]!=animals[N-1])and(s[N-2]=="x"):
        flag=flag+1
    elif (animals[N-3]==animals[N-1])and(s[N-2]=="o"):
        flag=flag+1
if (animals[N-1]=="W"):
    if (animals[N-2]!=animals[0])and(s[N-1]=="o"):
        flag=flag+1
    elif (animals[N-2]==animals[0])and(s[N-1]=="x"):
        flag=flag+1
else:
    if (animals[N-2]!=animals[0])and(s[N-1]=="x"):
        flag=flag+1
    elif (animals[N-2]==animals[0])and(s[N-1]=="o"):
        flag=flag+1
if flag==2:
    ans[0]="".join(animals)
#print(ans)
#続いて先頭が羊で、右が狼の時を考える
flag=0
animals=[""]*N
animals[0]="S"
if s[0] == "o":
    animals[N-1]="W"
    animals[1]="W"
else:
    animals[N-1]="S"
    animals[1]="W"
#print(animals)
for i in range(1,N-2):
    if animals[i]=="S":
        if s[i]=="o":
            animals[i+1]=animals[i-1]
        else:
            if animals[i-1]=="S":
                animals[i + 1] ="W"
            else:
                animals[i + 1] = "S"
    else:
        if s[i]=="x":
            animals[i + 1] = animals[i - 1]
        else:
            if animals[i-1]=="S":
                animals[i + 1] ="W"
            else:
                animals[i + 1] = "S"
    #print(animals)
if (animals[N-2]=="W"):
    if (animals[N-3]!=animals[N-1])and(s[N-2]=="o"):
        flag=flag+1
    elif (animals[N-3]==animals[N-1])and(s[N-2]=="x"):
        flag=flag+1
else:
    if (animals[N-3]!=animals[N-1])and(s[N-2]=="x"):
        flag=flag+1
    elif (animals[N-3]==animals[N-1])and(s[N-2]=="o"):
        flag=flag+1
if (animals[N-1]=="W"):
    if (animals[N-2]!=animals[0])and(s[N-1]=="o"):
        flag=flag+1
    elif (animals[N-2]==animals[0])and(s[N-1]=="x"):
        flag=flag+1
else:
    if (animals[N-2]!=animals[0])and(s[N-1]=="x"):
        flag=flag+1
    elif (animals[N-2]==animals[0])and(s[N-1]=="o"):
        flag=flag+1
if flag==2:
    ans[1]="".join(animals)
#print(ans)
#続いて先頭が狼で、右が狼の時を考える
flag=0
animals=[""]*N
animals[0]="W"
if s[0] == "o":
    animals[N-1]="S"
    animals[1]="W"
else:
    animals[N-1]="W"
    animals[1]="W"
#print(animals)
for i in range(1,N-2):
    if animals[i]=="S":
        if s[i]=="o":
            animals[i+1]=animals[i-1]
        else:
            if animals[i-1]=="S":
                animals[i + 1] ="W"
            else:
                animals[i + 1] = "S"
    else:
        if s[i]=="x":
            animals[i + 1] = animals[i - 1]
        else:
            if animals[i-1]=="S":
                animals[i + 1] ="W"
            else:
                animals[i + 1] = "S"
    #print(animals)
if (animals[N-2]=="W"):
    if (animals[N-3]!=animals[N-1])and(s[N-2]=="o"):
        flag=flag+1
    elif (animals[N-3]==animals[N-1])and(s[N-2]=="x"):
        flag=flag+1
else:
    if (animals[N-3]!=animals[N-1])and(s[N-2]=="x"):
        flag=flag+1
    elif (animals[N-3]==animals[N-1])and(s[N-2]=="o"):
        flag=flag+1
if (animals[N-1]=="W"):
    if (animals[N-2]!=animals[0])and(s[N-1]=="o"):
        flag=flag+1
    elif (animals[N-2]==animals[0])and(s[N-1]=="x"):
        flag=flag+1
else:
    if (animals[N-2]!=animals[0])and(s[N-1]=="x"):
        flag=flag+1
    elif (animals[N-2]==animals[0])and(s[N-1]=="o"):
        flag=flag+1
if flag==2:
    ans[2]="".join(animals)
#print(ans)
#続いて先頭が狼で、右が羊の時を考える
flag=0
animals=[""]*N
animals[0]="W"
if s[0] == "o":
    animals[N-1]="W"
    animals[1]="S"
else:
    animals[N-1]="S"
    animals[1]="S"
#print(animals)
for i in range(1,N-2):
    if animals[i]=="S":
        if s[i]=="o":
            animals[i+1]=animals[i-1]
        else:
            if animals[i-1]=="S":
                animals[i + 1] ="W"
            else:
                animals[i + 1] = "S"
    else:
        if s[i]=="x":
            animals[i + 1] = animals[i - 1]
        else:
            if animals[i-1]=="S":
                animals[i + 1] ="W"
            else:
                animals[i + 1] = "S"
    #print(animals)
if (animals[N-2]=="W"):
    if (animals[N-3]!=animals[N-1])and(s[N-2]=="o"):
        flag=flag+1
    elif (animals[N-3]==animals[N-1])and(s[N-2]=="x"):
        flag=flag+1
else:
    if (animals[N-3]!=animals[N-1])and(s[N-2]=="x"):
        flag=flag+1
    elif (animals[N-3]==animals[N-1])and(s[N-2]=="o"):
        flag=flag+1
if (animals[N-1]=="W"):
    if (animals[N-2]!=animals[0])and(s[N-1]=="o"):
        flag=flag+1
    elif (animals[N-2]==animals[0])and(s[N-1]=="x"):
        flag=flag+1
else:
    if (animals[N-2]!=animals[0])and(s[N-1]=="x"):
        flag=flag+1
    elif (animals[N-2]==animals[0])and(s[N-1]=="o"):
        flag=flag+1
if flag==2:
    ans[3]="".join(animals)
#print(ans)
flag=0
for i in range(4):
    if ans[i]!="":
        print(ans[i])
        flag=1
        break
if flag==0:
    print("-1")