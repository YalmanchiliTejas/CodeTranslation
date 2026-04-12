H,W=map(int,input().split())

A = [[0]*(W) for j in range(H+1)]

for i in range (H):
    A[i]=list(input()+".")

i=0
j=0
A[0][0]=0
while(True):
    if((i==(H-1))and(j==(W-1))):
        for k in range(H):
            if("#" in A[k]):
                print("Impossible")
                exit()
        print("Possible")
        exit()
    if(A[i+1][j]=="#"):
        A[i+1][j]=0
        i+=1
    elif(A[i][j+1]=="#"):
        A[i][j+1]=0
        j+=1
    else:
        print("Impossible")
        exit()




