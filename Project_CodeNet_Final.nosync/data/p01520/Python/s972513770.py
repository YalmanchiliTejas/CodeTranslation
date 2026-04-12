n,t,e=map(int, input().split())
x=list(map(int, input().split()))
number=-1

for i in range(n):
    for j in range(1,((t+e)//x[i])+1):
        if(j*x[i]>=t-e and j*x[i]<=t+e):
            number=i+1
            break
        
    else:
        continue
    break

print(number)
