while True:
    n=input()
    if n==0:break
    S=range(1,7)
    s=1
    for i in range(n):
        c=raw_input()
        if c=="North":
            S=[S[1],S[5],S[2],S[3],S[0],S[4]]
        elif c=="South":
            S=[S[4],S[0],S[2],S[3],S[5],S[1]]
        elif c=="East":
            S=[S[3],S[1],S[0],S[5],S[4],S[2]]
        elif c=="West":
            S=[S[2],S[1],S[5],S[0],S[4],S[3]]
        elif c=="Right":
            S=[S[0],S[2],S[4],S[1],S[3],S[5]]
        elif c=="Left":
            S=[S[0],S[3],S[1],S[4],S[2],S[5]]
        s+=S[0]
    print s