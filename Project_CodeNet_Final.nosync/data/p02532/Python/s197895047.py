n=input()
dic={}
for i in range(1,n+1):
    dic[str(i)]=[]
while True:
    c=raw_input().split()
    if c[0]=="push":
        dic[c[1]].append(c[2])
    elif c[0]=="pop":
        print dic[c[1]].pop()
    elif c[0]=="move":
        t=dic[c[1]].pop()
        dic[c[2]].append(t)
    elif c[0]=="quit":
        break