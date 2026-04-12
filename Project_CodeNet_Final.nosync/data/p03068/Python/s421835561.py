n=int(input())
s=input()
k=int(input())
a=s[k-1]
t=[]
for i in range(n):
    if(s[i] == a):
        t.append(s[i])
    else:
        t.append('*')
        continue
for j in range(n):
    print(t[j],end='')
print()