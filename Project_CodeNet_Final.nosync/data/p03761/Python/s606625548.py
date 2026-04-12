N=int(input())
s=list(input())
t=[list(input()) for i in range(N-1)]
u=[]
for i in s:
    for k in range(N-1):
        if i not in t[k]:
            break
    else:
        for j in range(N-1):
            t[j].remove(i)
        u.append(i)    
print("".join(sorted(u)))    