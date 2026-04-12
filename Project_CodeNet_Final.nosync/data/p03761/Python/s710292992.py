n=int(input())
s=[]
for i in range(n):
    a=input()
    s.append(a)


p=[]
for i in range(n):
    l=[0 for i in range(26)]
    for j in s[i]:
        if j=="a":
            l[0]+=1
        if j=="b":
            l[1]+=1
        if j=="c":
            l[2]+=1
        if j=="d":
            l[3]+=1
        if j=="e":
            l[4]+=1
        if j=="f":
            l[5]+=1
        if j=="g":
            l[6]+=1
        if j=="h":
            l[7]+=1
        if j=="i":
            l[8]+=1
        if j=="j":
            l[9]+=1
        if j=="k":
            l[10]+=1
        if j=="l":
            l[11]+=1
        if j=="m":
            l[12]+=1
        if j=="n":
            l[13]+=1
        if j=="o":
            l[14]+=1
        if j=="p":
            l[15]+=1
        if j=="q":
            l[16]+=1
        if j=="r":
            l[17]+=1
        if j=="s":
            l[18]+=1
        if j=="t":
            l[19]+=1
        if j=="u":
            l[20]+=1
        if j=="v":
            l[21]+=1
        if j=="w":
            l[22]+=1
        if j=="x":
            l[23]+=1
        if j=="y":
            l[24]+=1
        if j=="z":
            l[25]+=1
    p.append(l)

l=[]

for i in range(26):
    m=1000000000
    for j in range(n):
        m=min(m,p[j][i])
    l.append(m)
ans=""
for i in range(26):
    if i==0 and l[i]>0:
        ans+="a"*l[i]
    if i==1 and l[i]>0:
        ans+="b"*l[i]
    if i==2 and l[i]>0:
        ans+="c"*l[i]
    if i==3 and l[i]>0:
        ans+="d"*l[i]
    if i==4 and l[i]>0:
        ans+="e"*l[i]
    if i==5 and l[i]>0:
        ans+="f"*l[i]
    if i==6 and l[i]>0:
        ans+="g"*l[i]
    if i==7 and l[i]>0:
        ans+="h"*l[i]
    if i==8 and l[i]>0:
        ans+="i"*l[i]
    if i==9 and l[i]>0:
        ans+="j"*l[i]
    if i==10 and l[i]>0:
        ans+="k"*l[i]
    if i==11 and l[i]>0:
        ans+="l"*l[i]
    if i==12 and l[i]>0:
        ans+="m"*l[i]
    if i==13 and l[i]>0:
        ans+="n"*l[i]
    if i==14 and l[i]>0:
        ans+="o"*l[i]
    if i==15 and l[i]>0:
        ans+="p"*l[i]
    if i==16 and l[i]>0:
        ans+="q"*l[i]
    if i==17 and l[i]>0:
        ans+="r"*l[i]
    if i==18 and l[i]>0:
        ans+="s"*l[i]
    if i==19 and l[i]>0:
        ans+="t"*l[i]
    if i==20 and l[i]>0:
        ans+="u"*l[i]
    if i==21 and l[i]>0:
        ans+="v"*l[i]
    if i==22 and l[i]>0:
        ans+="w"*l[i]
    if i==23 and l[i]>0:
        ans+="x"*l[i]
    if i==24 and l[i]>0:
        ans+="y"*l[i]
    if i==25 and l[i]>0:
        ans+="z"*l[i]

print(ans)




