def check(li,N):
    for i in range(N):
        if (s[i]=='o' and li[i]==0)or(s[i]=='x' and li[i]==1):
            if(li[(i+1)%N]!=-1 and li[(i+1)%N]!=li[i-1]):
                return False
            else:
                li[(i+1)%N]=li[i-1]
        elif (s[i]=='o' and li[i]==1)or(s[i]=='x' and li[i]==0):
            if(li[(i+1)%N]!=-1 and li[(i+1)%N]==li[i-1]):
                return False
            else:
                li[(i+1)%N]=int(not li[i-1])
    return True
    
def output(li):
    for i in range(N):
        if li[i]==1:
            print('W',end='')
        else:
            print('S',end='')
    print()

N=int(input())
s=input()
for i in range(2):
    for j in range(2):
        li=[-1]*N
        li[0]=i
        if(i==0 and s[0]=='o')or(i==1 and s[0]=='x'):
            li[-1]=j;li[1]=j
        elif(i==1 and s[0]=='o')or(i==0 and s[0]=='x'):
            li[-1]=j;li[1]=j^1
        if(check(li,N)):
            output(li)
            exit()
print(-1)