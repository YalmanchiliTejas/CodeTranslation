n=input()
while True:
    dic={}
    for i in range(n):
        L=raw_input().split()
        dic[(-(3*int(L[1])+1*int(L[3])),i)]=L[0]
    for i in sorted(dic):
        print "%s,%d"%(dic[i],-i[0])
    n=input()
    if n==0:break
    print