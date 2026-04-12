N=int(input())
S=input()
c=S[int(input())-1]
T=""
for i in S:
    if i==c:
        T=T+i
    else:
        T=T+"*"
print(T)
