N=int(input())
H=list(map(int,input().split()))
count=0
d=False

for i in range(N):
    if H[i] >= max(H[:i+1]):
        d=True
    else:
        d=False
            
    if d:
        count +=1
    
        
print(count)   