n = int(input())
listS= list(input())
k=int(input())

index=0
while index < len(listS):
    if listS[index]!=listS[k-1]:
        listS[index]="*"
    index+=1

print("".join(listS))
