n=int(input())
s=input()
ans=0
for j in range(2):
    for k in range(2):
        ans1=""
        last=j+1 #狼1 羊2
        start=k+1
        a0=last
        a1=start
        for i in range(n):
            if a1==1:
                ans1+="W"
            else:
                ans1+="S"

            if [a0,a1]==[1,1] and s[i]=='o':
                a0=a1
                a1=2
            elif [a0,a1]==[1,1] and s[i]=='x':
                a0=a1
                a1=1
            elif [a0,a1]==[1,2] and s[i]=='o':
                a0=a1
                a1=1
            elif [a0,a1]==[1,2] and s[i]=='x':
                a0=a1
                a1=2
            elif [a0,a1]==[2,1] and s[i]=='o':
                a0=a1
                a1=1
            elif [a0,a1]==[2,1] and s[i]=='x':
                a0=a1
                a1=2
            elif [a0,a1]==[2,2] and s[i]=='o':
                a0=a1
                a1=2
            elif [a0,a1]==[2,2] and s[i]=='x':
                a0=a1
                a1=1

        if a0==last and a1==start:
            ans=1
            break
    if ans==1:
        break
if ans==1:
    print(ans1)

else:
    print(-1)