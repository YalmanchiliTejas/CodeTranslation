n,x=map(int,input().split())
len_l=[0]*(n+1)
len_l[0]=1
num_p=[0]*(n+1)
num_p[0]=1
for i in range(n):
    len_l[i+1]=3+2*len_l[i]
    num_p[i+1]=2*num_p[i]+1
def calc(a,b):
    if a==0:
        return 1
    if b<=0:
        return 0
    else:
        nagasa=len_l[a]
        if b==1:
            return 0
        elif b<=len_l[a-1]+1:
            return calc(a-1,b-1)
        elif b==len_l[a-1]+2:
            return num_p[a-1]+1
        elif b<=2*len_l[a-1]+2:
            return num_p[a-1]+1+calc(a-1, b-(len_l[a-1]+2))
        elif b==2*len_l[a-1]+3:
            return 2*num_p[a-1]+1
        else:
            print('okasi')
            return None
print(calc(n,x))
