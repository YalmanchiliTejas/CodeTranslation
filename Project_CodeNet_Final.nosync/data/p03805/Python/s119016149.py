import copy
s=list()

N,M=map(int,raw_input().split())
n=[[0 for i in range(N)] for j in range(N)]
for i in range(M):
        a,b=map(int,raw_input().split())
        n[a-1][b-1]=1
        n[b-1][a-1]=1
arrived=[0 for i in range(N)]

arrived[0]=1
def solve(s,arrived):
        narrived=copy.deepcopy(arrived)
        global n
        global N
        op=False
        ans=0
        for i in range(N):
                arrived=copy.deepcopy(narrived)
                if(s[i]==1 and arrived[i]!=1):
                        op=True
                        arrived[i]=1
                        ans+=solve(n[i],arrived)
        
        if(sum(arrived)==N and op==False):
                return 1
        elif(op==False):
                return 0
        return ans
                        
print(solve(n[0],arrived))
