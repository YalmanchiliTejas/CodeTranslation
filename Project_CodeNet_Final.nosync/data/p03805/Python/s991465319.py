N,M=map(int,input().split())
import copy
a=[0]*M
b=[0]*M
for i in range(M):
    a[i],b[i]=map(int,input().split())
D=[[1]]
def route(D):
    E=[]
    D1=copy.deepcopy(D)
    for j in range(len(D)):
        x=D[j][-1]
        for i in range(M):

            if a[i]==x:
                if not b[i] in D1[j]:
                    D[j]=copy.deepcopy(D1[j])
                    D[j].append(b[i])
                    E.append(D[j])
            elif b[i]==x:
                if not a[i] in D1[j]:
                    D[j]=copy.deepcopy(D1[j])
                    D[j].append(a[i])
                    E.append(D[j])
    return E
for i in range(N-1):
    D=copy.deepcopy(route(D))
print(len(D))

    