A,B,C,X,Y = map(int,(input().split()))

#ABピザの最大枚数
limit = max(X,Y)*2
Min = 10**10

for i in range(limit+1):
    a=0
    b=0
    c=0
    
    if i/2 < X:
        a = (X-int(i/2)) *A
    if i/2 < Y:
        b= (Y-int(i/2))*B    
        
    c = i*C
    
    Min = min(Min,a+b+c)
    
    
    
print(Min)
        
            



