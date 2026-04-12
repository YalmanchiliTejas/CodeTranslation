N=int(input())
s=list(map(int,input().split()))
x=0
view=0
for i in range(N): 
    if s[i]>=x:
        view+=1
        x=s[i]
print(view)    
    

