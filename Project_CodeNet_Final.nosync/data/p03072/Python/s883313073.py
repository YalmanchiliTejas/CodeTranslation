input()
*l,=map(int,input().split())
print(1+sum(max(l[0:i])<=l[i]for i in range(1,len(l))))