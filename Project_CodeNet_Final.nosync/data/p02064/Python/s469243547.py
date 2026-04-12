N,s,t = map(int,input().split())
Nod = []
print("?",s,t)
print(end = '',flush=True)
K = int(input())
for i in range(1,N+1):
    if i != s and i != t:
        print("?",s,i)
        print(end = '',flush=True)
        A = int(input())
        print("?",t,i)
        print(end = '',flush=True)
        B = int(input())
        if A+B == K:
            Nod.append([A,B,i])
Nod.sort()
ans = [s]
for a,b,c in Nod:
    ans.append(c)
print("!",end =" ")
for i in ans:
    print(i,end = " ")
print(t)
