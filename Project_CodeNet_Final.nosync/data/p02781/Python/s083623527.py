tmp=input()
n=int(tmp)
l=len(tmp)
k=int(input())
if k==1:
    ans=9*(l-1)
    last=int(tmp[0])
    ans+=last
    print(ans)
    exit()
if k==2:
    c=l-2
    ans=(9**2)*((c*(c+1))//2)
    num=0
    for i in range(1,l):
        for head_i in range(9,0,-1):
            for tail_i in range(9,0,-1):
                cal=str(head_i)
                cal+="0"*len(tmp[1:i])
                cal+=str(tail_i)
                cal+="0"*len(tmp[i+1:])
                if int(cal)<=n:
                    num+=1
    
    ans+=num
    print(ans)
    exit()


c=0
for i in range(3,l):
    c+=(i-1)*(i-2)//2
ans=(9**3)*c
num=0
for i in range(1,l):
    for j in range(i+1,l):
        for f_i in range(1,10):
            if f_i<int(tmp[0]):
                num+=81
                continue
            for s_i in range(1,10):
                for t_i in range(1,10):
                    cal=f_i*(10**(l-1))+s_i*(10**(l-1-i))+t_i*(10**(l-1-j))
                    if cal<=n:
                        num+=1
ans+=num
print(ans)