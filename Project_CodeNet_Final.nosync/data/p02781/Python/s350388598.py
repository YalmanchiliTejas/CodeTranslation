n=input()
k=int(input())


if int(n)<1000:
    c=0
    for i in range(1,int(n)+1):
       if len(str(i))-str(i).count("0")==k:
           c+=1
else:
    n_l=len(n)
    c=0
    if k==1:
        c=int(n[0])+9*(n_l-1)
    elif k==2:
        for i in range(2,n_l):
            c+=9*9*(i-1)
        c+=(int(n[0])-1)*9*(n_l-1)
        
        for i in range(1,n_l):
            if int(n[i])>0:
                c+=int(n[i])+(n_l-i-1)*9
                break

    else:
        for i in range(3,n_l):
            c+=9**3*((i-1)*(i-2)/2)
                    
        c+=(int(n[0])-1)*9*9*((n_l-1)*(n_l-2)/2)
        
        flag_i=False
        flag_j=False
        for i in range(1,n_l):
            if int(n[i])>0:
                flag_i=True
                for j in range(i+1,n_l):
                    if int(n[j])>0:
                        flag_j=True
                        break
            if flag_i:
                break
        if flag_i:
            c+=(int(n[i])-1)*9*(n_l-i-1)
            c+=9*9*((n_l-i-1)*(n_l-i-2)*0.5)
            if flag_j:
                c+=(int(n[j]))+9*(n_l-j-1)
                
print(int(c))