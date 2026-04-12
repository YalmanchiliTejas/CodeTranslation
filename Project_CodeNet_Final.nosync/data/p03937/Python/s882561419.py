h,w=map(int,input().split())
a=[[i for i in input()] for i in range(h)]
i=0
j=0
a[0][0]="."
while not(i==h-1 and j==w-1):
    if(i==h-1):
        if(a[i][j+1]=="#"):
            a[i][j+1]="."
            j+=1
        else:
            print("Impossible")
            break
    elif(j==w-1):
        if(a[i+1][j]=="#"):
            a[i+1][j]="."
            i+=1
        else:
            print("Impossible")
            break
    else:
        if(a[i][j+1]=="#" and not a[i+1][j]=="#"):
            a[i][j+1]="."
            j+=1
        elif(not a[i][j+1]=="#" and a[i+1][j]=="#"):
            a[i+1][j]="."
            i+=1
        else:
            print("Impossible")
            break
else:
    if any("#" in i for i in a):
        print("Impossible")
    else:
        print("Possible")