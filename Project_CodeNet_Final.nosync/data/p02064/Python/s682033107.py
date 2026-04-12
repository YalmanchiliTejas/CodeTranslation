N,s,t = map(int,input().split())

LIST=[]

print("?",s,t,flush=True)
d0=int(input())

for i in range(1,N+1):
    if i==s or i==t:
        continue
    print("?",s,i,flush=True)
    d1=int(input())
    print("?",t,i,flush=True)
    d2=int(input())

    if d1+d2==d0:
        LIST.append([d1,i])

LIST.sort()
ANS=[]

NOW=s
NOWd=0

for d,ans in LIST:
    print("?",NOW,ans,flush=True)
    d1=int(input())
    print("?",ans,t,flush=True)
    d2=int(input())

    if d1+d2==d0-NOWd:
        ANS.append(ans)
        NOWd+=d1
        NOW=ans

print("!",s,*ANS,t)



    

