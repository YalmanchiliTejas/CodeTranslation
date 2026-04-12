H,W=map(int,input().split())
field=[]
for i in range(H):
    field.append(input())

new_field=[]
for i in range(H):
    for j in range(W):
        if(field[i][j]=="#"):
            new_field.append(field[i])
            break

new_new_field=[]
for i in range(W):
    tmp=[]
    flag=0
    for j in range(len(new_field)):
        if(new_field[j][i]=="#"):
            flag=1
        tmp.append(new_field[j][i])
    if(flag==1):
        new_new_field.append(tmp)

for i in range(len(new_new_field[0])):
    for j in range(len(new_new_field)):
        print("{}".format(new_new_field[j][i]),end="")
    print()