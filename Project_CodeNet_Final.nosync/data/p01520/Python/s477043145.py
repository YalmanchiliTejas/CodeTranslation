
N,T,E = map(int,input().split())
x = list(map(int,input().split()))
l=[]

for i in range(len(x)):
    for j in range(T-E,T+E+1):
            if j% x[i]==0:
                l.append(i)
                
if not l:
    print(-1)
else:
    for i in l:
        print(i+1)
        break
                            
