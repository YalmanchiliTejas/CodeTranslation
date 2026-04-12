n=int(input())
ls=list(input())
k=int(input())
for i in range(n):
    if ls[i]!=ls[k-1]:
        ls[i]="*"
print("".join(ls))