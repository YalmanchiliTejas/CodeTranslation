n=int(input())
S=input()
k=int(input())
char=S[k-1]
out=""
for i in S:
    if i!=char:
        out+="*"
    else:
        out+=i
print(out)