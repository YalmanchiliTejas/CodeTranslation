n=int(input())
while n!=0:
    total=0
    saidai=None
    saishou=None
    for i in range(n):
        s=int(input())
        total+=s
        if saidai is None or s>saidai:
            saidai=s
        if saishou is None or s<saishou:
            saishou=s
    print((total-saidai-saishou)//(n-2))        
    n=int(input())   
    
