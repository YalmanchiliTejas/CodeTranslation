N=int(input())
S=str(input())
n=int(input())
d=S[n-1]
a=""
for i in S:
    if i!=d:
        a+="*"
    elif i==d:
        a+=i
print(a)
