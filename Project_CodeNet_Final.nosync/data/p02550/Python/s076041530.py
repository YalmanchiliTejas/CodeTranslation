n,x,m=map(int,input().split())
cnt2=set()
cnt2.add(x)
cnt3=[x]
cnt4=0
cnt5=0
cnt6=x
for i in range(1,m+10):
    num2=pow(cnt6,2,m)
    if num2 in cnt2:
        for j in range(len(cnt3)):
            if cnt3[j]==num2:
                cnt7=j
                break
        cnt10=len(cnt3)-cnt7
        num4=sum(cnt3[:cnt7])
        cnt4=len(cnt3)
        break
    cnt2.add(num2)
    cnt3.append(num2)
    cnt6=num2
    if num2==0:
        ans=sum(cnt3)
        cnt5=1
        break
if cnt5==0 and n>cnt4:
    ans=num4
    n-=cnt7
    ans+=(n//cnt10)*sum(cnt3[cnt7:])
    ans+=sum(cnt3[cnt7:(n%cnt10)+cnt7])
if cnt4>=n:
    ans=sum(cnt3[:n])
print(ans)
