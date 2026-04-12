n=int(input())
h1=input().split()
h2=[]
for i in range(n):
    h2.append(int(h1[i]))

c=0
for i in range(n):
    if max(h2[:i+1])==h2[i]:
        c+=1

print(c)
